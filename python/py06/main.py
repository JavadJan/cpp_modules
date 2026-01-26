from bureaubrat import Bureaucrat


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
	
	print("\033[1;33m\n[TEST 4:] Increment Bureaucrat\033[0m")
	try:
		f = Bureaucrat("foo", 2)
		print(f)
		f.increament_bureaucrat()
		f.increament_bureaucrat()
	except Exception as e:
		print("Invalid Grade:", e)


if __name__ == "__main__":
    main()