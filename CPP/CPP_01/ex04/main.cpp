/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:20:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/29 13:50:46 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	ReadReplace(std::string filename, std::string s1, std::string s2)	{
	size_t			pos;
	std::string		tmp;
	std::string		NewFile;
	std::ifstream	ifs(filename);
	
	if (!ifs.is_open())	{
		std::cout << "File doesn't exit/is corrupted" << std::endl;
		return (1);
	}
	
	std::ofstream	ofs(filename + ".replace");
	while (!ifs.eof())	
	{
		getline(ifs, tmp);
		while (1)
		{
			pos = tmp.find(s1, 0);
			if (pos == std::string::npos)
				break;
			tmp.erase(pos, s1.length());
			tmp.insert(pos, s2);
		}	
		NewFile.append(tmp);
		if (!ifs.eof())
			NewFile.append("\n");
	}
	ofs << NewFile;
	return (0);
}
	
int	main(int argc, char **argv)
{
	if (argc != 4)	{
		std::cout << "Please enter file, s1 and s2" << std::endl;
		return (1);
	}
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	return (ReadReplace(filename, s1, s2));
}
 