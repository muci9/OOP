# Assignment 5-6
OOP - Assignement 5-6
Name: Grave Matters
Description:
	Application for managing a morgue database with a twist.
It's an console-base application with a CLI. It recognises the following
commands:
	mode X - A is for administrator, B is for assitant
	exit
	Administrator commands:
		add name, origin, age, imageName - add a new profile
		delete name - delete a profile
		update name, newOrigin, newAge, newImageName - update a profile
		list - display all profiles
	Assistant commands:
		This are a little bit weirder, because the assignment is part
	of a story involving a serial killer. :))
		next - display the next profile, the assistant can only see 1 profile at a time
		save name - transfer the profile to a different repository consisting of profiles with no connection to the serial killer
		list [origin,] age - display only profiles with the requeste origin and age less or equal to one give, origin is an optional parameter
		mylist - display all transferred profiles

