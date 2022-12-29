/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/29 15:19:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

//////////////////////////////
// 							//
//		IDENTIFICATIONS		//
// 							//
//////////////////////////////

bool	is_char(std::string src)	{
	return (src.length() == 1 && !isdigit(src[0]));
}

bool	is_inff(std::string src)	{
	return (src == "-inff" || src == "+inff" ||src == "inff" || src == "nanf");
}

bool	is_inf(std::string src)	{
	return (src == "-inf" || src == "+inf" || src == "inf" || src == "nan");
}

bool	is_int(std::string src)	{
	for (size_t i = 0; i < src.length(); i++)
	{
		if (i == 0 && src[0] == '-')
			continue;
		if (!isdigit(src[i]))
			return (false);
	}
	return (true);
}

bool is_float(std::string src)
{
	int	dot = 0;
	for (size_t i = 0; i < src.length() - 1; i++)
	{
		if (i == 0 && src[0] == '-')
			continue;
		if (!isdigit(src[i]) && src[i] != '.')
			return (false);
		if (src[i] == '.')
			dot += 1;
	}
	return ((dot == 1) && src[src.length() - 1] == 'f');
}

bool is_double(std::string src)
{
	int dot = 0;
	for (size_t i = 0; i < src.length(); i++)
	{
		if (i == 0 && src[0] == '-')
			continue;
		if (!isdigit(src[i]) && src[i] != '.')
			return (false);
		if (src[i] == '.')
			dot += 1;
	}
	return (dot == 1);
}

//////////////////////////////
// 							//
//			DISPLAY			//
// 							//
//////////////////////////////

void	display_char(char dst)	{

	std::cout << "char: ";
	if (dst >= std::numeric_limits<char>::min()
		&& dst <= std::numeric_limits<char>::max())	{
		if (isprint(dst))
			std::cout << "'" << dst << "'\n";
		else
			std::cout << "Non displayable" << std::endl;	
	}
	else
		std::cout << "overflow" << std::endl;
}

void	display_int(int dst)	{

	std::cout << "int: ";
	if (dst >= std::numeric_limits<int>::min()
		&& dst <= std::numeric_limits<int>::max())
		std::cout << dst << std::endl;
	else
		std::cout << "overflow" << std::endl;
}

void	display_float(float dst)	{
	
	std::cout << "float: ";
	if (isnan(dst))	{
		std::cout << "nanf" << std::endl;
	}
	else if (isinf(dst))	{
		if (dst > 0)
			std::cout << std::numeric_limits<float>::infinity() << std::endl;
		else
			std::cout << -std::numeric_limits<float>::infinity() << std::endl;
	}
	else if (dst >= std::numeric_limits<float>::lowest()
		&& dst <= std::numeric_limits<float>::max())	{
		std::cout << std::setprecision(1) << std::fixed << dst << "f" << std::endl;
	}
	else
		std::cout << "overflow" << std::endl;
}

void	display_double(double dst)	{

	std::cout << "double: ";
	if (isnan(dst))	{
		std::cout << "nan" << std::endl;
	}
	else if (isinf(dst))	{
		if (dst > 0)
			std::cout << std::numeric_limits<double>::infinity() << std::endl;
		else
			std::cout << -std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (dst >= std::numeric_limits<double>::lowest()
		&& dst <= std::numeric_limits<double>::max())	{
		std::cout << std::setprecision(1) << std::fixed << dst << std::endl;
	}
	else
	std::cout << "overflow" << std::endl;
}

//////////////////////////////
// 							//
//		  CONVERSIONS		//
// 							//
//////////////////////////////


void	conversion_to_char(std::string	src)	{
	char	dst = static_cast<char>(src[0]);

	display_char(dst);
	display_int(static_cast<int>(dst));
	display_float(static_cast<float>(dst));
	display_double(static_cast<double>(dst));
}

void	conversion_to_int(std::string src)	{
	int		dst = stoi(src);

	display_char(static_cast<char>(dst));
	display_int(dst);
	display_float(static_cast<float>(dst));
	display_double(static_cast<double>(dst));
}

void	handle_inf_float(float dst)	{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";	
	display_float(dst);
	display_double(static_cast<double>(dst));
}

void	handle_inf_double(double dst)	{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";	
	display_float(static_cast<float>(dst));
	display_double(dst);
}
	
void	conversion_to_float(std::string	src)	{
	float	dst = stof(src);

	if (is_inff(src))	{
		handle_inf_float(dst);
		return ;
	}
	display_char(static_cast<char>(dst));
	display_int(static_cast<int>(dst));
	display_float(dst);
	display_double(static_cast<double>(dst));
}

void	conversion_to_double(std::string src)	{
	double	dst = stod(src);

	if (is_inf(src))	{
		handle_inf_double(dst);
		return ;
	}
	display_char(static_cast<char>(dst));
	display_int(static_cast<int>(dst));
	display_float(static_cast<float>(dst));
	display_double(dst);
}

//////////////////////////////
// 							//
//		 	MAIN			//
// 							//
//////////////////////////////

int	main(int argc, char **argv)	{
	if (argc != 2)	{
		std::cout << "Please enter one argument.\n";
		return 1;
	}
	std::string src = argv[1];

	if (is_char(src))
		conversion_to_char(src);
	else if (is_int(src))
		conversion_to_int(src);
	else if (is_float(src) || is_inff(src))
		conversion_to_float(src);
	else if (is_double(src) || is_inf(src))
		conversion_to_double(src);
	else
		std::cerr << "conversion impossible\n";
	return 0;
}