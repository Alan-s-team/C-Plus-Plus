
/*
 * Purpose: demostrate the usage of struct
 *
 * Author: Lunsheng Wang <lunsheng.wang@gmail.com>
 */

#ifndef USER_H
#define USER_H //These to prevent multi-times of including

struct User { //By default, the members in struct are public
	std::string first_name;
	std::string last_name;
	unsigned short age;
	std::string email;

	std::string get_status() //Getter. A struct can have methods, but in tradition, none
	{
		return status;
	}
	void set_status(std::string status) //Setter
	{
		if (status == "Gold" || status == "Silver" || status == "Bronze")
			this->status = status;
		else
			this->status = "No status";
	}

	private:
		std::string status = "Gold"; //Need -std=c++11 to compile
};

#endif
