#include<stdio.h>
#include<string.h>
struct car_station{
	char name[32];   //Name of the Car wash station
	int front;       //Index of Car being washing 
	int rear;        //Position of the last car
    int cars_count;  //Total no of cars presnt at wash station including the car being washed
    int total_cars;  //Cars washed by the wash station 
	int data[100]; 	 // Data of the cars present at the wash station
};
struct car_station station1, station2, station3;
void Enqueue(int car_number)  //Function to assign a car to the station with the shortest queue
{
	if(station1.cars_count == station2.cars_count && station1.cars_count == station3.cars_count )
	{
		station1.data[++station1.rear] = car_number;
		station1.cars_count++;
		station1.total_cars++;
	}
	else if(station1.cars_count <= station2.cars_count  && station1.cars_count <= station3.cars_count )
	{
	    station1.data[++station1.rear] = car_number;
		station1.cars_count++;
		station1.total_cars++;
	}
	else if(station2.cars_count <= station1.cars_count && station2.cars_count <= station3.cars_count )
    {
    	station2.data[++station2.rear] = car_number;
    	station2.cars_count++;
    	station2.total_cars++;
	}
	else
	{
		station3.data[++station3.rear] = car_number;
		station3.cars_count++;
		station3.total_cars++;
	}
}
void Dequeue(int station_number) //Function to send the car out of station after the completion of washing
{
	if(station_number == 1)
	{
		if(station1.cars_count==0)
		{
			printf("No cars at %s \n",station1.name);
		}
		else
		{
	    	station1.front++;
	    	station1.cars_count--;
	    }
	}
	else if(station_number == 2)
	{
		if(station2.cars_count==0)
		{
			printf("No cars at %s \n",station2.name);
		}
		else
		{
			station2.front++;
			station2.cars_count--;
	    }
	}
	else if(station_number == 3)
	{   if(station3.cars_count==0)
		{
			printf("No cars at %s \n",station3.name);
		}
		else
		{
			station3.front++;
			station3.cars_count--;
	    }
	}
	else
	{
		printf("Please enter valid station number\n");
	}

}
void status() //Function to display the no of cars in the stations including the car being washed
{
	if(station1.cars_count == 0) printf("There are no cars at %s\n", station1.name);
	else if(station1.cars_count == 1)
	{
	    printf("Car%d is at Washing at %s\n", station1.data[station1.front], station1.name);
	    printf("No cars are in queue for washing at %s\n", station1.name);
	}
	else{
	    printf("Car%d is at Washing at %s\n", station1.data[station1.front], station1.name);
	    printf("%d cars are in queue for washing at %s\n", station1.cars_count-1, station1.name);
    }
    if(station2.cars_count == 0) printf("There are no cars at %s\n", station2.name);
    else if(station2.cars_count == 1)
	{
	    printf("Car%d is at Washing at %s\n", station2.data[station2.front],station2.name);
	    printf("No cars are in queue for washing at %s\n", station2.name);
	}
    else{
	    printf("Car%d is at Washing at %s\n", station2.data[station2.front],station2.name);
	    printf("%d cars are in queue for washing at %s\n", station2.cars_count-1, station2.name);
    }
    if(station3.cars_count==0) printf("There are no cars at %s\n", station3.name);
    else if(station3.cars_count==1)
	{
	    printf("Car%d is at Washing at %s\n", station3.data[station3.front],station3.name);
	    printf("No cars are in queue for washing at %s\n", station3.name);
	}
    else{
	    printf("Car%d is at Washing at %s\n", station3.data[station3.front],station3.name);
	    printf("%d cars are in queue for washing at %s\n", station3.cars_count-1, station3.name);	
    }
   
}
void Position(int car_number) //Position of a particular car 
{
	int i,j=0,flag=0;
	for(i=station1.front;i<=station1.rear;i++,j++)
	{
		if(station1.data[i]==car_number)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		if(i==station1.front)
		{
			printf("Car%d is in washing area at %s\n",car_number,station1.name);
		}
		else
		{
			printf("Car%d is at %d position in %s\n",car_number,j,station1.name);
		}
	}
	j=0;
	if(flag==0)
	{
		for(i=station2.front;i<=station2.rear ;i++,j++)
		{
			if(station2.data[i]==car_number)
			{
				flag=2;
				break;
			}
		}
	}
	if(flag==2)
	{
		if(i==station2.front)
		{
			printf("Car%d is in washing area at %s\n",car_number,station2.name);
		}
		else
		{
			printf("Car%d is at %d position in %s\n",car_number,j,station2.name);
		}
	}
	j=0;
	if(flag==0)
	{
		for(i=station3.front;i<=station3.rear;i++,j++)
		{
			if(station3.data[i]==car_number)
			{
				flag=3;
				break;
			}
		}
	}
	if(flag==3)
	{
		if(i==station3.front)
		{
			printf("Car%d is in washing area at %s\n",car_number,station3.name);
		}
		else
		{
			printf("Car%d is at %d position in %s\n",car_number,j,station3.name);
		}
	}
	if(flag==0)
	{
		printf("Car%d does not exist in any station\n",car_number);
	}
}
int main()
{
	station1.front = 0;
	char a[32] = "Giraffe", b[32] = "Panda", c[32] = "Elephant";
	strcpy( station1.name , a );
	station1.rear = -1;
	station1.cars_count = 0;
	station2 = station1;
	strcpy( station2.name , b );
	station3 = station1;
	strcpy( station3.name , c );
	printf("WELCOME TO JUMANJI\n");  //Car garage name
	printf("Enter the price to wash one car\n");
	int price;
	scanf("%d",&price );
	int option;
    int car_number= 1;
    while(1)
	{
		printf("\n1.New car arrival\n2.Removal of a car from a station\n3.Status of a particular station\n4.Status of a particular car\n5.Sale of the day\n");
        scanf("%d",&option);
        if(option == 1)
        {
        	Enqueue(car_number);
        	car_number++;
		}
		else if(option == 2)
		{
			printf("From which station: 1.%s 2.%s 3.%s \n",station1.name,station2.name,station3.name);
			int station_number;
			scanf("%d",&station_number);
			Dequeue(station_number);
		}
		else if(option == 3)
		{
			status();
			printf("Total cars in JUMANJI: %d\n",station1.cars_count+station2.cars_count+station3.cars_count);
		}
		else if(option == 4)
		{
			printf("Enter the car name\n");
			char car[20];
			scanf("%s",car);
			int number;
			scanf("%d",&number);
			Position(number);
		}
		else if(option == 5)
		{
			printf("Sale of the day: %d/- \n", (car_number-1)*price );
			if(station1.total_cars==station2.total_cars && station1.total_cars==station3.total_cars )
			{
				printf("Three stations earned equally for the day\n");
			}
			else if(station1.total_cars >= station2.total_cars && station1.total_cars >= station3.total_cars)
			{
				printf("%s earned more than other stations \n",station1.name);
			}
			else if(station2.total_cars >= station1.total_cars && station2.total_cars >= station3.total_cars)
			{
				printf("%s earned more than other stations \n",station2.name);
			}
			else if(station3.total_cars >= station1.total_cars && station3.total_cars >= station2.total_cars)
			{
				printf("%s earned more than other stations \n",station3.name);
			}
		}
		else
		{
			break;
		}
    }  
}