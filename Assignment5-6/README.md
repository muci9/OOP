# Assignment 5-6
OOP - Assignement 5-6<br/>
Name: Grave Matters<br/>
Description:<br/>
	Application for managing a morgue database with a twist.<br/>
	It's an console-base application with a CLI. It recognises the following<br/>
Commands:<br/>
	mode X - A is for administrator, B is for assitant<br/>
	exit<br/>
	Administrator commands:<br/>
		add name, origin, age, imageName - add a new profile<br/>
		delete name - delete a profile<br/>
		update name, newOrigin, newAge, newImageName - update a profile<br/>
		list - display all profiles<br/>
	Assistant commands:<br/>
		This are a little bit weirder, because the assignment is part<br/>
	of a story involving a serial killer. :))<br/>
		next - display the next profile, the assistant can only see 1 profile at a time<br/>
		save name - transfer the profile to a different repository consisting of profiles with no connection to the serial killer<br/>
		list [origin,] age - display only profiles with the requeste origin and age less or equal to one give, origin is an optional parameter<br/>
		mylist - display all transferred profiles<br/>

