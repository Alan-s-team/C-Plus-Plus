/*
 * Purpose: demostrate the usage of struct
 *
 * Author: Lunsheng Wang <lunsheng.wang@gmail.com>
 */

#include<iostream>
#include<vector>

#include "user.h"

int add_user(std::vector<User> &users, User usr)
{
	int i;
	for (i = 0; i < users.size(); i++) {
		if (users[i].first_name == usr.first_name &&
			users[i].last_name == usr.last_name) {
			std::cout << "The user already exists at " << i << std::endl;
			return i;
		}
	}
	users.push_back(usr);
	//std::cout << "The user is added at " << i << std::endl;
	return i;
}

int main()
{

	User me;
	std::vector<User> users;

	me.first_name = "Alan";
	me.last_name = "Wang";
	me.age = 30;
//	me.status = "Gold"; //Error, for it is private member
	std::cout << "Status: " << me.get_status() << std::endl;

	add_user(users, me);

	User usr1, usr2, usr3;
	usr1.first_name = "Grace";
	usr1.last_name = "Chen";

	usr2.first_name = "Jenny";
	usr2.last_name = "Wang";

	usr3.first_name = "Abigale";
	usr3.last_name = "Wang";

	add_user(users, usr1);
	add_user(users, usr2);
	add_user(users, usr3);
	std::cout << "Vector size = " <<  users.size() << std::endl;

	User usr;
	usr.first_name = "Abigale";
	usr.last_name = "Wang";
	add_user(users, usr);
	std::cout << "Vector size = " <<  users.size() << std::endl;

	return 0;
}
