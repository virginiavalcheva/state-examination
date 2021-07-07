#include <iostream>
#include <cstring>

using namespace std;

class User {
private:
	char* email;
	char* username;
	int age;

	void copyData(char* email, char* username, int age) {
		this->email = new char[strlen(email) + 1];
		strcpy_s(this->email, strlen(email) + 1, email);

		this->username = new char[strlen(username) + 1];
		strcpy_s(this->username, strlen(username) + 1, username);

		this->age = age;
	}

public:
	User() : email(new char[1]), username(new char[1]), age(0) {
		strcpy_s(email, 1, "");
		strcpy_s(username, 1, "");
	}

	User(char* email, char* username, int age) {
		copyData(email, username, age);
	}

	User(const User& other) {
		copyData(other.email, other.username, other.age);
	}

	User& operator=(const User& rhs) {
		if (this != &rhs) {
			delete[] email;
			delete[] username;
			copyData(rhs.email, rhs.username, rhs.age);
		}
		return *this;
	}

	~User() {
		delete[] email;
		delete[] username;
	}

	void setEmail(const char* email) {
		delete[] this->email;
		this->email = new char[strlen(email) + 1];
		strcpy_s(this->email, strlen(email) + 1, email);
	}

	void setUsername(const char* username) {
		delete[] this->username;
		this->username = new char[strlen(username) + 1];
		strcpy_s(this->username, strlen(username) + 1, username);
	}

	const char* getEmail() const {
		return email;
	}

	const char* getUsername() const {
		return username;
	}

	const int getAge() const {
		return age;
	}

	//prefix
	void operator++() {
		++age;
	}

	//postfix
	void operator++(int x) {
		age += 2;
	}

	bool operator==(const User& user) const {
		return this->age == user.age;
	}

	bool operator!=(const User& user) const {
		return this->age != user.age;
	}

	bool operator<(const User& user) const {
		return this->age < user.age;
	}

	//unary
	User operator-() const {
		User result;
		result.age = -age;
		result.setEmail(email);
		result.setUsername(username);
		return result;
	}

	//binary
	User operator-(const User& user) const {
		User result; 
		result.age = this->age - user.age;
		result.setEmail(email);
		result.setUsername(username);
		return result;
	}

	User& operator-=(const User& user) {
		age -= user.age;
		setEmail(user.email);
		setUsername(user.username);
		return *this;
	}

};

ostream& operator<<(ostream& os, const User& user) {
	os << user.getEmail();
	return os;
}

istream& operator>>(istream& is, User& user) {
	char newEmail[20];
	is >> newEmail;
	user.setEmail(newEmail);
	return is;
}

int main() {

	User user = User("test@abv.bg", "test", 20);
	const char* email = user.getEmail();
	const char* username = user.getUsername();

	cout << email << " " << username << " " << user.getAge() << endl;

	user.setEmail("test2@abv.bg");

	cout << user.getEmail() << " " << user.getUsername() << " " << user.getAge() << endl;

	User user1 = User(user);

	cout << user1.getEmail() << " " << user1.getUsername() << " " << user1.getAge() << endl;

	User user2 = user1;

	cout << user2.getEmail() << " " << user2.getUsername() << " " << user2.getAge() << endl;

	user++;
	cout << user.getAge() << endl;

	++user;
	cout << user.getAge() << endl;

	cout << (user == user1) << endl;

	cout << (user != user1) << endl;

	cout << (user < user1) << endl;

	User user4 = -user;

	cout << user4.getAge() << " " << user4.getEmail() <<  endl;

	User user5 = user - user1;

	cout << user5.getAge() << " " << user5.getEmail() << endl;

	user -= user1;

	cout << user.getAge() << " " << user.getEmail() << endl;

	User user6; 
	cin >> user6;
	cout << user6;

	return 0;
}