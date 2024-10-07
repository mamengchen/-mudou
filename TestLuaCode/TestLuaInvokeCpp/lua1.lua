local student_obj = Student.create()
Student.set_name(student_obj,"Jack")
--Student:set_name("Jack") 如果这样写，会报错
print("0000000000000");
Student.print(student_obj)
print("sssssssssssss修改20岁");
Student.set_age(student_obj, 20);
local _age = Student.get_age(student_obj);
print("lua打印年龄：",_age);