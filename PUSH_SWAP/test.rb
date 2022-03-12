require "open3"

PATH = "./"
CHECKER = "checker_Mac"

if ARGV.length != 2
	puts "wrong number of arguments, need 2: amount of iterations and length of input"
	exit
end

system("make -C #{PATH}", [:out, :err ] => File::NULL)
if $?.exitstatus != 0
	puts "make failed"
	exit
end


if !File.file?("#{PATH}push_swap")
	puts "executable not found, check path or executable name"
	exit
end

if defined?(CHECKER) && !CHECKER.empty? && !File.file?(PATH + CHECKER)
	puts "checker \"%s\" doesn't exist, remove variable \"CHECKER\" or set it to an empty string if there is no checker" % [PATH + CHECKER]
	exit
end

total = 0
amount = ARGV[0].to_i
input_length = ARGV[1].to_i
max = -1
min = -1
slowest_input = ""
(0...amount).each do |i|
	arg = (0...input_length).to_a.shuffle.join(' ')
	out = `./#{PATH}push_swap #{arg}`
	if defined?(CHECKER) && !CHECKER.empty?
		Open3.popen3("./#{PATH}#{CHECKER} #{arg}") do |i, o, e, t|
			i.print out
			i.close
			check = o.gets
			if check != "OK\n"
				puts "ERROR:"
				puts arg
				puts check
				exit
			end
		end
	end
	count = out.split("\n", -1).length
	count -= 1 if count != 0 #because of last \n
	if count > max
		max = count
		slowest_input = arg
	end
	if count < min || min == -1
		min = count
	end
	puts count
	total += count
end

puts "min: %d\nmax: %d\naverage: %d\nslowest input:\n%s" % [min, max, total / amount, slowest_input]