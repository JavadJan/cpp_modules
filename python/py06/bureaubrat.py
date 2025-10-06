from form import Form

class Bureaucrat:
	def __init__(self, name : str, grade:int):
		self._name = name
		if grade < 1:
			raise Bureaucrat.GradeTooHighException()
		if grade > 150:
			raise Bureaucrat.GradeTooLowException()
		self._grade = grade
		print("Called Bureaucrat default constructor")

	# derived exception class
	class GradeTooHighException(Exception):
		def __str__(self):
			return "Grade is out of range(Too High)"
	class GradeTooLowException(Exception):
		def __str__(self):
			return "Grade is out of range(Too Low)"
	
	# methods
	def increament_bureaucrat(self):
		if self._grade <= 1:
			raise Bureaucrat.GradeTooHighException()
		self._grade -= 1
		print(f"{self.name} promoted {self._grade}")

	def decreament_bureaucat(self):
		if self._grade >= 150:
			raise Bureaucrat.GradeTooLowException()
		self._grade +=1
		print(f"{self._name} demoted {self._grade}")

	def signForm(self, f:Form):
		try:
			f.beSign(self)
			print(f"{self._name} signed {f.getName()}")
		except Exception as e:
			print(f"{self.name} couldn’t sign {f.get_name()} because {e}")

	#getter
	@property
	def name(self):
		return self._name
	@property
	def grade(self):
		return self._grade
	
	#overload operator
	def __str__(self):
		return f"{self._name}, bureaucrat grade{self._grade}"
	

