#include "person.h"

Person::Person()
{
}

Person::Person(const QString &firstName, const QString &initials, const QString &familyName) :
        m_firstName(firstName), m_initials(initials), m_familyName(familyName)
{

}

const QString &Person::firstName() const
{
    return m_firstName;
}

const QString &Person::initials() const
{
    return m_initials;
}

const QString &Person::familyName() const
{
    return m_familyName;
}

void Person::setFirstName(const QString &firstName)
{
    m_firstName = firstName;
}

void Person::setInitials(const QString &initials)
{
    m_initials = initials;
}

void Person::setFamilyName(const QString &familyName)
{
    m_familyName = familyName;
}
