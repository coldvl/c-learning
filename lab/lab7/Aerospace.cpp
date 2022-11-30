#include <iostream> 
#include <string>
 
class Aerospace
{
private:
	std::string m_name;
	std::string m_color;
 
public:
	Aerospace(std::string name, std::string color)
		: m_name(name), m_color(color)
	{
	}
 
	std::string getName() const { return m_name; }
	std::string getColor() const { return m_color; }
 
};
 
class PassangerPlane : public Aerospace
{
private:
	int m_seats;
 
public:
	PassangerPlane(std::string name, std::string color, int seats)
		:Aerospace(name, color), m_seats(seats)
	{
	}
 
	int getSeats() const { return m_seats; }
 
	friend std::ostream& operator<<(std::ostream &out, const PassangerPlane &a)
	{
		out << "PassangerPlane (" << a.getName() << ", " << a.getColor() << ", " << a.getSeats() << ")\n";
		return out;
	}
};
 
class SportPlane : public Aerospace
{
public:
	SportPlane(std::string name, std::string color)
		:Aerospace(name, color)
	{
	}
 
	friend std::ostream& operator<<(std::ostream &out, const SportPlane &b)
	{
		out << "SportPlane (" << b.getName() << ", " << b.getColor() << ")\n";
		return out;
	}
 
};

class Glider : public Aerospace
{
public:
	Glider(std::string name, std::string color)
		:Aerospace(name, color)
	{
	}
 
	friend std::ostream& operator<<(std::ostream &out, const Glider &b)
	{
		out << "Glider (" << b.getName() << ", " << b.getColor() << ")\n";
		return out;
	}
 
};

class Fighter : public Aerospace
{
public:
	Fighter(std::string name, std::string color)
		:Aerospace(name, color)
	{
	}
 
	friend std::ostream& operator<<(std::ostream &out, const Fighter &b)
	{
		out << "Fithter (" << b.getName() << ", " << b.getColor() << ")\n";
		return out;
	}
 
};

class Bomber : public Aerospace
{
private:
int m_maxWeightCarrying;

public:
	Bomber(std::string name, std::string color, int maxWeightCarrying)
		:Aerospace(name, color), m_maxWeightCarrying(maxWeightCarrying)
	{
	}
	
	int getMaxWeightCarrying() const { return m_maxWeightCarrying; }

	friend std::ostream& operator<<(std::ostream &out, const Bomber &b)
	{
		out << "Bomber (" << b.getName() << ", " << b.getColor() << ", " << b.getMaxWeightCarrying() << ")\n";
		return out;
	}
 
};

int main()
{
	const PassangerPlane a("Airbus A350", "black", 348);
	std::cout << a;
 
	const SportPlane b("KP-2U Sova", "white-yellow");
	std::cout << b;

    const Glider c("Flugzeugbau DG-800", "white");
	std::cout << c;

	const Fighter d("Raptor F-22", "black");
	std::cout << d;

	const Bomber e("Boeing B-52 Stratofortress", "black", 32000);
	std::cout << e;
 
	return 0;
}