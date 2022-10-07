#include<stdio.h>           //Import function from library
#include<stdlib.h>			//Import function from library
#include <string.h>         //Import function from library

struct Account{  			//Build a struct to make easy to combine the person's data into one
		char name[30];      //Char variable assign for name
		int ID; 			//Int variable to assign for ID 
		char Position[10];  //Char variable to assign the Position
		int hp;             //Int variable to assign the hourly payment
	} e;                    //This struct can be expressed by e

int empID;  				//Int variable for the ID especially for the functions
int recsize = sizeof(e);    //Record the size of the e 
int menu;    				//Int variable to get the number to enter each functions
char Infor[2000];			//Char variable which used to save the last txt file

int main(){					//Declare new funtion
	FILE *fp, *ft, *fy;     //used for file opening		
	char pick;				//char which used to know whether to do the function again or not

	while(1){				//While(1), do the following
		printf("\n1. Add Record\n");					//Print this sentence for UI
		printf("2. List Records\n");					//Print this sentence for UI
		printf("3. Update Records\n");					//Print this sentence for UI
		printf("4. Delete Record\n");					//Print this sentence for UI
		printf("5. Find Records\n");					//Print this sentence for UI
		printf("6. Exit\n");							//Print this sentence for UI
		printf("-----------------------\n");			//Print this sentence for UI
		printf("Your Choice: ");						//Print this sentence for UI
		scanf("%d", &menu);								//Scan the User's response
		switch (menu) {									//According to menu, each function will be excuted
			case 1:										//When user press 1
				printf("\nRecord Mode \n\n");			//Print this sentence for UI
				pick = 'y';								//Set pick as y to proceed the following
				while(pick == 'y'){						//While pick is y do the following
					if(fy == NULL){
						fp = fopen("Save.txt","w");
						printf("Enter nickname: ");		//Print this sentence for UI
						scanf("%s", e.name);				//Scan the user's response
						printf("Enter ID: ");				//Print this sentence for UI
						scanf("%d", &e.ID);					//Scan the user's response
						printf("Enter Position: ");			//Print this sentence for UI
						scanf("%s", e.Position);			//Scan the user's response
						printf("Enter hourly pay: ");		//Print this sentence for UI
						scanf("%d", &e.hp);					//Scan the user's response
						fy = fopen("Save.txt","a");			//Open the file Save.txt to append 
						fwrite(&e, recsize, 1,fy);			//Save the scanned information into the Save.txt file
					}else{
						char tempname[30];
						int tempID;
						char tempPosition[10];
						int temphp;
						printf("Enter nickname: ");		//Print this sentence for UI
						scanf("%s", tempname);				//Scan the user's response
						printf("Enter ID: ");				//Print this sentence for UI
						scanf("%d", &tempID);				//Scan the user's response
						printf("Enter Position: ");			//Print this sentence for UI
						scanf("%s", tempPosition);			//Scan the user's response
						printf("Enter hourly pay: ");		//Print this sentence for UI
						scanf("%d", &temphp);					//Scan the user's response
						while(fread(&e, recsize, 1, fy) != EOF){   //read the file specific number times from Save.txt and if it is equal to 1 do the following 
							if(e.ID == tempID){
								printf("Duplicated ID. Please Put Another ID\n");
								break;
							}break;
						}
						printf("Certificated\n");
						snprintf(e.name, sizeof(e.name),"%s",tempname);    //Saved the whole contents of the Save.txt in the variable Infor
						e.ID = tempID;
						snprintf(e.Position, sizeof(e.Position),"%s",tempPosition);    //Saved the whole contents of the Save.txt in the variable Infor
						e.hp = temphp;
						fy = fopen("Save.txt","a");			//Open the file Save.txt to append 								
						fwrite(&e, recsize, 1,fy);			
					}
					fclose(fy);							//Close the file
					//fclose(fp);
					printf("Record another information? (y or n): ");  //Ask Question for doing the function again or not
					scanf("%s", &pick);					//Scan the user's response
				} break;

			case 2:										//When user press 2
				printf("\nList Mode \n\n");				//Print this sentence for UI
				fy = fopen("Save.txt","r");				//Open the file named Save.txt to read the content of it
				rewind(fy);
				while(fread(&e, recsize, 1, fy)==1){	//Read the file specific number times from Save.txt and if it is equal to 1 do the following 
					printf("\n%s %d %s %d",e.name,e.ID, e.Position, e.hp); 	//Print the person's information 
				}break;									//Break the pharse

			case 3:										//When user press 3
				printf("\nUpdate Mode \n\n");			//Scan the user's response
				pick = 'y';								//Set pick as y to proceed the following
				while (pick == 'y'){					//While pick is y do the following
					printf("Enter the employee's ID to modify: ");		//Print this sentence for UI
					scanf("%d", &empID);				//Scan the user's response
					rewind(fy);							//refresh the file 
					while(fread(&e,recsize,1,fy)==1){   //read the file specific number times from Save.txt and if it is equal to 1 do the following 
						if(e.ID == empID){				//If the saved ID and scanned ID are same number
							printf("\nEnter new name, ID, Position, and Hourly Pay: ");		//Print this sentence for UI
							scanf("%s%d%s%d",e.name,&e.ID,e.Position,&e.hp); 	//Require the new employee's information 
							fseek(fy,-recsize,SEEK_CUR);							//Cursering the data place to replace the data
							fwrite(&e,recsize,1,fy);								//Rewrite information based on the scanned information
							break;
						}															//Break the pharase
					}
					printf("Update another information? (y or n): ");				//Ask Question for doing the function again or not
					scanf("%s", &pick);												//Scan the user's response
				}break;																//Break the phrase

			case 4:																	//When user press 4
				printf("\nDelete Mode \n\n");										//Print this sentence for UI
				pick = 'y';															//Set pick as y to proceed the following
				while(pick == 'y'){													//While pick is y and fy is not null, do the following
					printf("\nEnter ID of the employee to delete: ");				//Print this sentence for UI
					scanf("%d", &empID);											//Scan the user's response
					ft = fopen("Temp.txt","w");										//Open the Temp.txt file to write the information
					rewind(fy);														//refresh the file
					while(fread(&e,recsize,1,fy)==1){								//read the file specific number times from Save.txt and if it is equal to 1 do the following 
						if(e.ID != empID){											//If the saved ID and newly scanned ID is different
							fwrite(&e, recsize,1,ft);								//Write its information in the Temp.txt file
						}
					}
					fclose(fy);														//Close the Save.txt file
					fclose(ft);														//Close the Temp.txt file
					remove("Save.txt");												//Erase the Save.txt file
					rename("Temp.txt","Save.txt");									//Change name Temp.txt file to Save.txt file
					//fy = fopen("Save.txt","r");
					printf("Delete another information? (y or n): ");				//Print this sentence for UI
					scanf("%s", &pick);												//Scan the user's response
				}break;

			case 5:																	//When user press 5
				printf("\nFinding Mode \n\n");										//Print this sentence for UI
				printf("Input Employee's ID: ");									//Print this sentence for UI
				scanf("%d", &empID);												//Scan the user's response
				fy = fopen("Save.txt","r");											//Open the Save.txt file to read
				rewind(fy);															//Refresh the Save.txt file 
				while(fread(&e,recsize,1,fy)==1){									//read the file specific number times from Save.txt and if it is equal to 1 do the following 
					if(e.ID == empID){												//If the saved ID and scanned ID are same
						printf("\n%s %d %s %d\n",e.name,e.ID, e.Position, e.hp);	//Print the structed information 
					}
				}break;																//Break the phrase

			case 6:																	//When user press 6
				printf("Exit from program.\n");										//Print this sentence for UI
				fy = fopen("Save.txt","r");											//Open the Save.txt file to read
				fp = fopen("Employee_data.txt","w");								//Open the Employee_data.txt file to write
				while(fread(&e, recsize, 1, fy)==1){								//read the file specific number times from Save.txt and if it is equal to 1 do the following 
					snprintf(Infor, sizeof(Infor),"%s %d %s %d\n",e.name,e.ID, e.Position, e.hp);    //Saved the whole contents of the Save.txt in the variable Infor
					//Infor = ("\n%s %d %s %d",e.name,e.ID, e.Position, e.hp);
					fprintf(fp,"%s",Infor);											//Print the Infor into the Employee_data.txt
				}
				fclose(fp);															//Close the file
				fclose(fy);															//Close the file
				exit(0);															//Exit (to get out from While(1) loop)
			default:																//If different number pressed
				printf("Invalid Input");											//Print Invalid Input 
				break;																//Break
			}
		}
	}