#include "../include/TraficLight.hpp"

TraficLight::TraficLight() : t_light(RED)
{
}

std::string TraficLight::to_string(enum STATE s)
{
	switch (s)
	{
	case RED:
		return ("RED");
	case GREEN:
		return ("GREEN");
	case YELLOW:
		return ("YELLOW");
	default:
		return ("UNKNOWN");
	}
}

void TraficLight::install()
{
	while (1)
	{
		std::cout << "current state: " << to_string(t_light) << " ";
		switch (t_light)
		{
		case RED:
		{
			std::cout << "🔴 ";
			std::cout << "Vehicles are crossing for 10 second\n";
			usleep(10000000);
			t_light = GREEN; // becomes green, turning state into grean
			break ;
		}
		case GREEN:
		{
			std::cout << "🟢 ";
			std::cout << "pedestrians has 5 second to across the street\n";
			usleep(5000000);
			t_light = YELLOW; // becomes green, turning state into grean
			break ;
		}
		case YELLOW:
		{
			std::cout << "🟡 ";
			std::cout << "Warning the trafic light is gonna RED\n";
			usleep(1000);
			t_light = RED; // becomes green, turning state into grean
			break ;
		}
		default:
			break ;
		}
	}
}