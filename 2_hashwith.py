size=10

def insert_data(client_list):
		
		
		il=int(input("Enter the id of client:"))
		name=input("Enter the name of client:")
		telephone=input("Enter the Telephone number ofclient:")
		x=il%10
	
		chain=None
		p=x

		while(client_list[x]!=None):
			x=x+1

		
		client_list[x]=[il,name,telephone,chain]
		m=client_list[p]
		if(p<x):
			if(client_list[p][0]%10!=client_list[x][0]%10):
				client_list[p]=[il,name,telephone,chain]
				client_list[x]=m
				y=client_list[x][0]%size
				
				while(client_list[y][3]==client_list[x][0]):
					y=client_list[y][3]
				client_list[y][3]=x
		if(p<x):
			if(client_list[p][0]%10==client_list[x][0]%10):
				while(client_list[p][3]!=None):
					p=client_list[p][3]
				client_list[p][3]=x
		


def search(client_list,key):
	x=key%10
	while(client_list[x]!=None and key!=client_list[x][0] and client_list[x][3]!=None ):
		x=client_list[x][3]
	if(client_list[x]!=None and key==client_list[x][0]):
	 	print("client found at", x," index")
	else:
		print(key," Not found....")		

def delete(client_list):
	key=int(input("Enter the id of deleted client:"))
	x=key%10
	p=x
	while(key!=client_list[x][0]):
		x=client_list[x][3]
	
	while(client_list[p][3]!=x):
		p=client_list[p][3]
	client_list[p][3]=None							
	if(client_list[x][3]!=None):
		client_list[p][3]=client_list[x][3]
	client_list[x]=None

def main():
	
	client_list=[None]*size


	while True:
	
		print("1.Insert the data:")
		print("2.Display the data:")
		print("3.Search the data:")
		print("4.Delete the data:")
		print("5.Exit")
		ch=int(input("Enter your choise:"))
		if(ch==1):
			insert_data(client_list)
			
	
		elif(ch==2):
			print("client list:\n")
			print(client_list)
		elif(ch==3):
			key=int(input("Enter the key for searching the client:"))
			search(client_list,key)
		elif(ch==4):
			delete(client_list)

		elif(ch==5):
			break
		else:
			print("Invalid Input....")

main()
