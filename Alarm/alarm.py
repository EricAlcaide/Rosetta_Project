import winsound, time, os, platform


def sound():

	for i in range(2): 
		
		for j in range(9): 
			
			winsound.MessageBeep(-1) 
		
		time.sleep(2) 

def alarm(n):
	
	print()
	print("Wait time:", n, "seconds.")
	time.sleep(n) 
	
	sound()

def input_destinations(user_input):

	if user_input == 1:
		
		user_input = int(input("Enter the desired hours: "))
		
		wait_time = (user_input * 60) * 60
		alarm(wait_time)
	
	elif user_input == 2:
		
		user_input = int(input("Enter the desired minutes: "))
		
		wait_time = user_input * 60
		alarm(wait_time)

	elif user_input == 3:

		user_input = int(input("Enter the desired seconds: "))

		wait_time = user_input
		alarm(wait_time)

	elif user_input == 4:

		hours = int(input("Hours: "))
		minutes = int(input("Minutes: "))
		seconds = int(input("Seconds: "))

		wait_time = ((hours*60)*60) + (minutes*60) + seconds
		print(wait_time)
		alarm(wait_time)

	else:
		print("Invalid Input")
		main()		
		
def main():
	print("What unit of time do you want to wait?\n (1) Hours\n (2) Minutes\n (3) Seconds\n (4) Combination")
	user_input = input(": ")
	
	input_destinations(user_input)

	return;

main()