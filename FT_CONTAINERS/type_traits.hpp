/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:10:24 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/23 18:04:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// ^----------------------------------------------------^
// ^													^
// ^				 	ENABLE_IF						^
// ^													^
// ^----------------------------------------------------^

template <bool B, typename T = void> 
struct enable_if {};

template <typename T> 
struct enable_if<true, T> {
	typedef T	type;
};

// ^----------------------------------------------------^
// ^													^
// ^				 	IS_INTEGRAL						^
// ^													^
// ^----------------------------------------------------^

template<class T, T v>
struct integral_constant {
	const static T					value = v;
	typedef T						value_type;
	typedef	integral_constant<T, v>	type;
};

typedef	integral_constant<bool, true>	true_type;
typedef	integral_constant<bool, false>	false_type;

template<class>
struct is_integral : public false_type {};

template<>
struct is_integral<int> : public true_type {};

template<>
struct is_integral<unsigned int> : public true_type {};

template<>
struct is_integral<bool> : public true_type {};

template<>
struct is_integral<char> : public true_type {};

template<>
struct is_integral<signed char> : public true_type {};

template<>
struct is_integral<unsigned char> : public true_type {};

template<>
struct is_integral<char16_t> : public true_type {};

template<>
struct is_integral<char32_t> : public true_type {};

template<>
struct is_integral<short> : public true_type {};

template<>
struct is_integral<unsigned short> : public true_type {};

template<>
struct is_integral<long> : public true_type {};

template<>
struct is_integral<unsigned long> : public true_type {};

template<>
struct is_integral<long long> : public true_type {};

template<>
struct is_integral<unsigned long long> : public true_type {};

