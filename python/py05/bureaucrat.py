class Bureaucrat:
	grade_limit = {"min": 1, "max":150}

	class GradeTooHighException(Exception):
		def __str__(self):
			return "Grade is out of range(Too High)"
	class GradeTooLowException(Exception):
		def __str__(self):
			return "Grade is out of range(Too Low)"
		
	def __init__(self, name:str, grade = int):
		self._name = name #_name it mean this attribute is private
		if grade < Bureaucrat.grade_limit["min"]:
			raise Bureaucrat.GradeTooHighException()
		if grade > Bureaucrat.grade_limit["max"]:
			raise Bureaucrat.GradeTooLowException()
		self._grade = grade #_ says that this variable is in private specifier
		print("called constructor\n")
	def increament_bureaucrat(self):
		if self._grade <= Bureaucrat.grade_limit["min"]:
			raise Bureaucrat.GradeTooHighException()
		self._grade -= 1
		print(f"{self._name} promoted {self._grade}")

	def decreament_bureaucrat(self):
		if self._grade >= Bureaucrat.grade_limit["max"]:
			raise Bureaucrat.GradeTooLowException()
		self._grade += 1
		print(f"{self._name} demoted {self._grade}")
	
	@property
	def name(self):
		return self._name
	@property
	def grade(self):
		return self._grade
	
	def __str__(self):
		return f"{self._name}, bureaucrat grade {self._grade}"
	
	
def main():
	print("[TEST 1:] Too Low")
	try:
		b = Bureaucrat("javad", -1)
	except Exception as e:
		print("Invalid Grade", e)

	print("[TEST 2:] Too High")
	try:
		a = Bureaucrat("Alex", 151)
	except Exception as e:
		print("Invalid Grade: ", e)

	print("[TEST 3:] Valid and Decreament")
	try:
		c = Bureaucrat("Baba", 149)
		print(c)
		c.decreament_bureaucrat()
		c.decreament_bureaucrat()
	except Exception as e:
		print("Invalid Grade:", e)
	
	print("\n[TEST 4:] Increment Bureaucrat")
	try:
		f = Bureaucrat("foo", 2)
		print(f)
		f.increament_bureaucrat()
		f.increament_bureaucrat()
	except Exception as e:
		print("Invalid Grade:", e)


if __name__ == "__main__":
    main()

		