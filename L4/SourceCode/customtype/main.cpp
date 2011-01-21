#include <QApplication>

#include <QList>
#include <QFile>
#include <QDataStream>
#include <QHash>
#include <QVariant>

#include "person.h"

// Insert code for exercise step 3 here

// Insert code for exercise step 4 here

// Insert code for exercise step 5 here

// Do not modify code below this line (except activating code for exercise steps 4 and 5)

void savePeople(const QList<Person> &people)
{
    QFile file("persons.dat");
    if(!file.open(QIODevice::WriteOnly))
        return;

    QDataStream stream(&file);

    stream << people;

    file.close();
}

QList<Person> loadPeople()
{
    QList<Person> result;

    QFile file("persons.dat");
    if(!file.open(QIODevice::ReadOnly))
        return result;

    QDataStream stream(&file);

    stream >> result;

    return result;
}

void saveAndLoadPeople(QList<Person> people)
{
    qDebug("Original people");
    foreach(const Person &p, people)
        qDebug("  %s %s %s", qPrintable(p.firstName()), qPrintable(p.initials()), qPrintable(p.familyName()));

    savePeople(people);
    people = loadPeople();

    qDebug("Loaded people");
    foreach(const Person &p, people)
        qDebug("  %s %s %s", qPrintable(p.firstName()), qPrintable(p.initials()), qPrintable(p.familyName()));
}

void hashOfPeople()
{
//    QHash<Person, int> age;
//
//    age[Person("John", "", "Doe")] = 42;
//    age[Person("Jane", "", "Doe")] = 36;
//    age[Person("Albert", "A", "Einstein")] = 76;
//
//    if(42 != age[Person("John", "", "Doe")])
//        qDebug("Something's wrong with John");
//    if(36 != age[Person("Jane", "", "Doe")])
//        qDebug("Something's wrong with Jane");
//    if(76 != age[Person("Albert", "A", "Einstein")])
//        qDebug("Something's wrong with Albert");
}

void variantsOfPeople(QList<Person> people)
{
//    qDebug("Original variants of people");
//    foreach(const Person &p, people)
//        qDebug("  %s %s %s", qPrintable(p.firstName()), qPrintable(p.initials()), qPrintable(p.familyName()));
//
//    QList<QVariant> variantList;
//
//    foreach(const Person &p, people)
//        variantList << QVariant::fromValue(p);
//
//    people.clear();
//    foreach(const QVariant &v, variantList)
//        people << v.value<Person>();
//
//    qDebug("People after variants");
//    foreach(const Person &p, people)
//        qDebug("  %s %s %s", qPrintable(p.firstName()), qPrintable(p.initials()), qPrintable(p.familyName()));
}

int main(int argc, char **argv)
{
    QApplication a(argc, argv);


    Person johnD("John","","Doe");
    Person janeD("Jane","","Doe");

    QList<Person> people;
    people << johnD << janeD << Person("Albert", "A", "Einstein");

    saveAndLoadPeople(people);
    hashOfPeople();
    variantsOfPeople(people);

    return 0;
}
