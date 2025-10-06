#from bureaubrat import Bureaucrat

class Form:
	def __init__(self, grade_exe:int , grade_sign:int, name:str, signed:bool):
		self._grade_exe = grade_exe
		self._grade_sign = grade_sign
		self._name = name
		self._signed = signed

	@property
	def getName(self):
		return self._name
	@property
	def getGradeExe(self):
		return self._grade_exe
	
	@property
	def getGradeSign(self):
		return self._grade_sign
	@property
	def getGradeSign(self):
		return self._grade_sign
	
	class GradeTooHighException(Exception):
		def __str__(self):
			return "Grade is out of range(Too High)"
	class GradeTooLowException(Exception):
		def __str_(self):
			return "Grade is out of range(Too Low)"
	
	#methods
	def beSign(self,   b: "Bureaucrat"):
		if (b.getGrade < self.getGradeSign):
			self._signed = True
		else:
			raise Form.GradeTooLowException()

