
contacts = {}

def read_Contacts():
	file = open("storege.txt","r")

	contactString = file.readline()

	file.close()

	readNumber = ""
	readName = ""
	set_ = False
	contacts = {}

	for letter in contactString:
		if letter.isdigit() == False and set_ == True:
			contacts[readName] = readNumber
			readName = ""
			readNumber = ""
			set_ = False
		elif letter.isalpha() or letter == "_":
			readName = readName + letter
		elif letter.isdigit():
			readNumber = readNumber + letter
			set_ = True
			
	
	return contacts


def rmv_Contact():

	file = open("storege.txt","w")

	name = input("who would you like to remove? ")

	file.close()


print("")
print("Hello, this program is for storing your contacts.") 
print(" ")

while True:

	contacts = read_Contacts()

	print("-"*20)

	if contacts == {}:
		print("You have no contacts")
	else:
		for name, numb in contacts.items():
			print("Phone number of %s is %s" % (name, numb))
			print(" ")

	answer = input("Would ypu like to 'add' or 'rmv' any contacts? ")
	
	str(answer)
	
	if answer == "add":
	
		name = input("What is the name of your contact? ")
		number = input("What is the number of your contact? ")
	
		contacts[name] = str(number)

		file = open("storege.txt","w")

	
		file.write(repr(contacts))
	

		file.close()

	elif answer == "rmv":

		file = open("storege.txt","w")

		name = input("who would you like to remove? ")

		file.close()

	elif answer == "quit":
		break

	else:
		print("Error")
