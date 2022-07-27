########################################
#           HW2 (python 3.7)           #
#         Indentation : 1 tap          #
########################################

# import module random for choice()
import random


# Person class
class Person:
    # initialization : Require parameter (이름, 주민등록번호, 성별)
    def __init__(self, name, ssn, ForM):
        self.__name = str(name)
        self.__ssn = str(ssn)
        self.__ForM = str(ForM)

    # __str__ : For modify result of print(instance of Person class)
    def __str__(self):
        return "이름 :" + str(self.__name) + "\n" + \
               "주민등록번호 : " + str(self.__ssn) + "\n" + \
               "성별 : " + str(self.__ForM) + "\n"

    # getter/setter
    def getName(self):
        return self.__name

    def getSsn(self):
        return self.__ssn

    def getForM(self):
        return self.__ForM


""" Complete a Employee class """


# Employee class
class Employee(Person):
    # class variables
    TOTAL_EMP = 0  # For current employees count
    Eid_COUNT = 0  # To assign an employee id conut

    # construntor : initialization with parameters (Person object, supervisor Eid, salary value)
    def __init__(self, person, supervisor=0, salary=0):
        super().__init__(person.getName(), person.getSsn(), person.getForM())

        self.__eid = str(10000 + Employee.Eid_COUNT)
        self.__supervisor = str(supervisor)
        self.__salary = str(salary)

        Employee.TOTAL_EMP += 1
        Employee.Eid_COUNT += 1

    # __str__ : For modify result of print(instance of Person class)
    def __str__(self):
        return "이름 :" + super().getName() + "\n" + \
               "주민등록번호 : " + super().getSsn() + "\n" + \
               "성별 : " + super().getForM() + "\n" + \
               "사원번호 : " + str(self.__eid) + "\n" + \
               "상사 사원번호 : " + str(self.__supervisor) + "\n" + \
               "월급 : " + str(self.__salary) + '$' + "\n"
        # 기존꺼는 super를 이용해서 상위 클래스의 멤버에 접근한다.
        # 기존꺼 이외에도 사원번호, 상사 사원번호, 월급을 추가한다.


    # getter/setter
    # 상위 클래스와 마찬가지로 기본적인 반환, 세팅
    def getEid(self):
        return self.__eid

    def getSupervisor(self):
        return self.__supervisor

    def getSalary(self):
        return self.__salary

    def setSupervisor(self, supervisor):
        self.__supervisor = supervisor

    def setSalary(self, salary):
        self.__salary = salary

    # destructor
    def __del__(self):
        Employee.TOTAL_EMP -= 1
        # 삭제될때 전체 직원의 개수를 1 감소



"""write a function code : return instance of Person class by ssn"""
"""                         parameters : person_list, ssn        """


def getPersonInfo(P, ssn):
    # P 리스트를 순회하면서 주민번호가 같은 person 객체를 반환한다.
    for person in P:
        if person.getSsn() == ssn:
            return person

    return None


"""write a function code : return instance of Employee class by eid"""
"""                         parameters : emp_list, eid             """


def getEmpInfo(E, eid):
    # E 리스트를 순회하면서 eid가 같은 employee 객체를 반환한다.
    for emp in E:
        if emp.getEid() == eid:
            return emp

    return None


"""write a function code : return list of supervisees of eid"""
"""                         parameters : emp_list, eid      """


def getSupervisee(E, eid):
    
    # 상관 번호가 eid인 객체를 넣을 빈 리스트
    _list = []

    # E 리스트를 순회하면서 supervisor가 eid와 같으면 리스트에 추가한다.
    for emp in E:
        if emp.getSupervisor() == eid:
            _list.append(emp)

    return _list


"""write a function code for print supervisor/see eid realationship chart """


# You can Change the parameters, and Create additional functions, if you want. #
# hint : Using getSupercisee function  ( refer to HW2 ppt )                    #
def printRelationship(E):
    ceo = None

    # supervisor가 None이면 ceo
    for emp in E:
        if emp.getSupervisor() == "None":
            ceo = emp

    # ceo를 기준으로 프린트하는 재귀함수를 호출
    printSuperviseeReculsive(E, ceo.getEid(), 0)


def printSuperviseeReculsive(E, eid, depth):
    
    # depth만큼 띄어쓰기
    for i in range(0, depth):
        print("\t", end="")

    # eid 출력
    print("->" + eid)

    # supervisor가 eid인 객체가 담긴 리스트
    emp_list = getSupervisee(E, eid)

    ## 리스트를 순회하면서 depth를 한 단계 올린뒤 재귀 호출
    for emp in emp_list:
        printSuperviseeReculsive(E, emp.getEid(), depth+1)


########################################### DO NOT MODIFY HERE ###########################################
def main():
    person_list = []
    emp_list = []

    p = Person("SH LEE", "999999999", "M")
    person_list.append(p)

    e = Employee(p, "10000", 2345)
    emp_list.append(e)

    print("*" * 70)
    print()

    """ print Employee getter/setter method : correct -> 5 points """
    print(e.getName())
    print(e.getSsn())
    print(e.getForM())
    print(e.getEid())
    print(e.getSupervisor())
    print(e.getSalary())

    e.setSupervisor("None")
    e.setSalary(3456)
    print(e.getSupervisor())
    print(e.getSalary())
    print()
    """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

    print(getPersonInfo(person_list, p.getSsn()))
    print()

    """ print getEmpInfo() function and __str__() method : correct -> 8 points """
    print(getEmpInfo(emp_list, e.getEid()))
    print()
    """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

    person_list = []
    emp_list = []
    del p
    del e
    Employee.TOTAL_EMP = 0
    Employee.Eid_COUNT = 0

    # For storing person in person_list #
    # Using "person.txt"file            #
    with open("person.txt", "r") as f_person:
        for line in f_person.readlines():
            person_info = line.rstrip().split("\t")

            p = Person(person_info[0], person_info[1], person_info[2])
            person_list.append(p)

    # It is similar to person_list storing code, but requires processing of the hire and retirement. #
    # Also, Provide handling of retired supervisee                                                   #
    # Using getPersonInfo(), getEmpInfo(), getSupervisee() functions                                 #
    #       "Hire&RetirementLOG.txt" file, import module random for choice()                         #

    with open("Hire&RetirementLOG.txt", "r") as f_log:
        for line in f_log.readlines():
            log = line.rstrip().split("\t")

            if (log[0] == "Hire"):
                e = Employee(getPersonInfo(person_list, log[1]), log[3], log[4])
                emp_list.append(e)

            elif (log[0] == "Retirement"):
                e = getEmpInfo(emp_list, log[1])

                eid = e.getEid()
                super_eid = e.getSupervisor()

                emp_list.pop(emp_list.index(e))
                del e

                """  Operating getSupervisee() function : correct -> 5 points  """
                s = getSupervisee(emp_list, super_eid)
                e = getSupervisee(emp_list, eid)

                if s != []:
                    em = random.choice(s)

                    for emp in e:
                        emp.setSupervisor(em.getEid())
                else:

                    for emp in e:
                        emp.setSupervisor("10000")
                """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

    print("*" * 70, end="\n\n")
    index = 0
    for emp in emp_list:
        if index % 10 == 0:  # Avoid too much output
            print(emp)
        index += 1

    print("*" * 70, end="\n\n")

    """  print supervisor/see realationship chart : correct -> 15 points """
    printRelationship(emp_list)
    """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

    print("*" * 70, end="\n\n")

    """print class variables : correct -> 2 points"""

    print("NUM OF CURRENT EMPLOYEES     : ", Employee.TOTAL_EMP)
    print()
    print("COUNT FOR ASSIGN EMPLOYEE ID : ", Employee.Eid_COUNT)
    print("\n" + "*" * 70)


main()
##########################################################################################################