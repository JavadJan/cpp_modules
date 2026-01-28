/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:20:00 by mkhavari          #+#    #+#             */
/*   Updated: 2026/01/27 15:20:28 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

bool	dateFormat(std::string dateStr)
{
	if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-'
		|| !isdigit(dateStr[0]) || !isdigit(dateStr[1]) || !isdigit(dateStr[2])
		|| !isdigit(dateStr[3]) || !isdigit(dateStr[5]) || !isdigit(dateStr[6])
		|| !isdigit(dateStr[8]) || !isdigit(dateStr[9]))
	{
		// record.error = "Error: bad input => " + dateStr;
		// date_price.push_back(record);
		return (false);
	}
	return (true);
}

std::tm time_struct(const std::string& dateStr) {
	std::tm tm;
    std::memset(&tm, 0, sizeof(tm));

    // Example format: "2024-11-07"
    sscanf(dateStr.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);

    tm.tm_year -= 1900;  // years since 1900
    tm.tm_mon -= 1;      // months since January

    return tm;
}