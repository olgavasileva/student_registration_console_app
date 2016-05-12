
A console application to maintain a simple student database.


    Main menu has 5 options:
    "1. Add Records"
    "2. List Records"
    "3. Modify Records"
    "4. Delete Records"
    "5. Exit"

After a user chooses any of the option they will be asked to enter a filename for the record IFF filename wasn't set yet.

1. Creating a new record:
    --ID
     -checks if 9 chars long
     -checks if contains only numerical
       -notifies about not satisfied upper conditions and loops again to give
       the user chance to enter the id again (doesn't exit to the main manu or quits the program)

    --NAME
     -has to contain first and last name separated by whitespaces
    
    --YEAR OF STUDY
     -if the user chooses non existing option (like 'r' or '8'), the program would loop
     and offer choices again (doesn't exit to the main manu or quits the program)
    
    --GENDER
     -if the user chooses non existing option (like 'r' or '8'), the program would loop
     and offer choices again (doesn't exit to the main manu or quits the program)

If everything is successful, the program shows the recorded info and success message and exits to the main menu

2. List records
      2.1 Displays all the records on file
      2.2 Display individual record
        - the user is asked to enter a student ID
          -if ID is not on file, the user is informed of it, the program would loop
          and offer to enter ID again (doesn't exit to the main manu or quits the program) OR to enter q to quit to the main menu, which is very convenient, because if a user cannot remember the right ID they won't stuck on this screen
          - is ID is found the program shows the record AND offers to enter another ID

3. Modify Records
      - the user is asked to enter a student ID
        - if ID is not on file, the user is informed of it, the program would loop
          and offer to enter ID again (doesn't exit to the main manu or quits the program) OR to enter q to quit to the main menu, which is very convenient, because if a user cannot remember the right ID they won't stuck on this screen
      -the user is asked what they would like to change: name, year, or gender
      -if user chooses, lets say, name, they are asked to enter a new one
      -further user is asked if they would like to change another property, lets say, gender, if they choose yes, thay can change another property ot change the name again.
      -then the user is shown the result of their modification. If the user is satisfied with it, they can save the changes
      -if an erro raised while the user tried to modify and save the changes (an error in the file recording), they are informed about it and the program enters the main menu

4. Delete Records
      -the user is asked to enter Students ID
        -if found, a user is asked for the confirmation
        -if not found, the program would loop
          and offer to enter ID again (doesn't exit to the main manu or quits the program) OR to enter q to quit to the main menu, which is very convenient, because if a user cannot remember the right ID they won't stuck on this screen

5. Exit
      -exits the program, asking user if they are sure they want to exit
      -if not, returns to main menu
