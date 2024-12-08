#include<iostream>
#include<Windows.h>
using namespace std;

class Person 
{
protected:
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* Name, int Age)
	{
		cout << "Construct Person\n";
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
		age = Age;
	}

	void Print() const
	{
		cout << "Output Person\n";
		cout << "Name: " << name << endl
			<< "Age: " << age << endl;
	}

	void Input()
	{
		char buff[20];
		cin.getline(buff, 20);
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);

		cin >> age;
	}

	~Person()
	{
		if (name != nullptr)
		{
			delete[] name;
		}
		cout << "Destruct Person\n";
		Sleep(1000);
	}
};

class Student : public Person
{
	char* Univer;
public:
	Student() = default;

	Student(const char* n, int a, const char* u) : Person(n, a)
	{
		cout << "Constructor Student\n";
		Univer = new  char[strlen(u) + 1];
		strcpy_s(Univer, strlen(u) + 1, u);
	}
	~Student()
	{
		delete[]Univer;
		cout << "Destruct Student\n";
		Sleep(1000);
	}
	void Print()
	{
		cout << "Output Student\n";
		Person::Print();
		cout << "University: " << Univer << endl;
	}
	void Input(const char* u)
	{
		delete[]Univer;
		Univer = new  char[strlen(u) + 1];
		strcpy_s(Univer, strlen(u) + 1, u);
		Person::Input();
	}
};

class Teacher : public Person {
	char* school;
	double salary;
	char* subjects[5];

public:
	Teacher() = default;

	Teacher(const char* n, int a, const char* s, double sal, const char* sub[], int numSubjects) : Person(n, a), salary(sal) {
		cout << "Construct Teacher\n";
		school = new char[strlen(s) + 1];
		strcpy_s(school, strlen(s) + 1, s);

		for (int i = 0; i < numSubjects && i < 5; i++) {
			subjects[i] = new char[strlen(sub[i]) + 1];
			strcpy_s(subjects[i], strlen(sub[i]) + 1, sub[i]);
		}
	}

	~Teacher() {
		delete[] school;
		for (int i = 0; i < 5 && subjects[i] != nullptr; i++) {
			delete[] subjects[i];
		}
		cout << "Destruct Teacher\n";
		Sleep(1000);
	}

	void Print() const {
		cout << "Output Teacher\n";
		Person::Print();
		cout << "School: " << school << endl;
		cout << "Salary: " << salary << endl;
		cout << "Subjects: ";
		for (int i = 0; i < 5 && subjects[i] != nullptr; i++) {
			cout << subjects[i] << " ";
		}
		cout << endl;
	}

	void Input(const char* s, double sal, const char* sub[], int numSubjects) {
		delete[] school;
		school = new char[strlen(s) + 1];
		strcpy_s(school, strlen(s) + 1, s);
		salary = sal;

		for (int i = 0; i < 5 && subjects[i] != nullptr; i++) {
			delete[] subjects[i];
		}
		for (int i = 0; i < numSubjects && i < 5; i++) {
			subjects[i] = new char[strlen(sub[i]) + 1];
			strcpy_s(subjects[i], strlen(sub[i]) + 1, sub[i]);
		}
	}
};

class Driver : public Person {
	char* autoNumber;
	char* driverLicenseNumber;

public:
	Driver() = default;

	Driver(const char* n, int a, const char* an, const char* dl) : Person(n, a) {
		cout << "Construct Driver\n";
		autoNumber = new char[strlen(an) + 1];
		strcpy_s(autoNumber, strlen(an) + 1, an);
		driverLicenseNumber = new char[strlen(dl) + 1];
		strcpy_s(driverLicenseNumber, strlen(dl) + 1, dl);
	}

	~Driver() {
		delete[] autoNumber;
		delete[] driverLicenseNumber;
		cout << "Destruct Driver\n";
		Sleep(1000);
	}

	void Print() const {
		cout << "Output Driver\n";
		Person::Print();
		cout << "Auto Number: " << autoNumber << endl;
		cout << "Driver's License Number: " << driverLicenseNumber << endl;
	}

	void Input(const char* an, const char* dl) {
		delete[] autoNumber;
		autoNumber = new char[strlen(an) + 1];
		strcpy_s(autoNumber, strlen(an) + 1, an);

		delete[] driverLicenseNumber;
		driverLicenseNumber = new char[strlen(dl) + 1];
		strcpy_s(driverLicenseNumber, strlen(dl) + 1, dl);

		Person::Input();
	}
};

class Doctor : public Person {
	char* specialization;
	int experience;

public:
	Doctor() = default;

	Doctor(const char* n, int a, const char* spec, int exp) : Person(n, a), experience(exp) {
		cout << "Construct Doctor\n";
		specialization = new char[strlen(spec) + 1];
		strcpy_s(specialization, strlen(spec) + 1, spec);
	}

	~Doctor() {
		delete[] specialization;
		cout << "Destruct Doctor\n";
		Sleep(1000);
	}

	void Print() const {
		cout << "Output Doctor\n";
		Person::Print();
		cout << "Specialization: " << specialization << endl;
		cout << "Experience: " << experience << " years" << endl;
	}

	void Input(const char* spec, int exp) {
		delete[] specialization;
		specialization = new char[strlen(spec) + 1];
		strcpy_s(specialization, strlen(spec) + 1, spec);
		experience = exp;
		Person::Input();
	}
};

int main()
{
	Person a("Oleg", 19);
	a.Print();

	Student student("John", 20, "MIT");
	student.Print();

	const char* subjects[] = { "Math", "Physics", "Chemistry" };
	Teacher teacher("Alice", 30, "High School", 3500.0, subjects, 3);
	teacher.Print();

	Driver driver("Bob", 45, "AB123CD", "D1234567");
	driver.Print();

	Doctor doctor("Clara", 50, "Cardiology", 20);
	doctor.Print();

	system("pause");
	return 0;
}