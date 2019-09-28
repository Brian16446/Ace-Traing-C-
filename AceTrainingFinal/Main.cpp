#include <iostream>
#include "Course.h"
#include "Student.h"
#include <fstream>
#include <vector>
#include <sstream>

#include "SCLinkedList.h"



using namespace std;

void displayCourses(vector<Course> &c);
void displayStudents(vector<student> &s);

int Course::numCourses = 0;
int student::numOfStudents = 0;
vector <string> students;


/* MENU FUNCTION DECLARATIONS */
void displayMainMenu();


int main() {
	


	displayMainMenu();

	/*/
	SCLinkedList *sc = new SCLinkedList();
	SCNode * SCtemp = new SCNode;

	student *s = new student();
	s->createStudent();

	
	sc->createNode(s->getID(), s->getForename(), s->getSurname(), s->getCourseName());


	student *s1 = new student();
	s1->createStudent();


	sc->createNode(s1->getID(), s1->getForename(), s1->getSurname(), s1->getCourseName());

	
	student *s2 = new student();
	s2->createStudent();


	sc->createNode(s2->getID(), s2->getForename(), s2->getSurname(), s2->getCourseName());
	sc->display();

	int r = sc->searchNodeNumber(sc->head, 2);
	cout << r;
	*/
	
	return 0;
}


