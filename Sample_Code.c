printf("Enter nickname: ");		 
scanf("%s", tempname);			 
printf("Enter ID: ");				 
scanf("%d", &tempID);				 
printf("Enter Position: ");			 
scanf("%s", tempPosition);			 
printf("Enter hourly pay: ");	 
scanf("%d", &temphp);		
fy = fopen("Save.txt","r");		 
while(fread(&e,recsize,1,fy)==1){   
	if(tempID == e.ID){
		printf("Duplicated ID. Please Put Another ID\n");
		goto First;
		}
	}

printf("Certificated\n");
snprintf(e.name, sizeof(e.name),"%s",tempname);     
e.ID = tempID;
snprintf(e.Position, sizeof(e.Position),"%s",tempPosition);    
e.hp = temphp;