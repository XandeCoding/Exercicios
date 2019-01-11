import pickle

def write_file ():
	"""Escreve um dicionario em um arquivo"""
	pickle_file = open ("pickle1.dat", "wb")
	dicionario = ["Academia de Computação", "Base de Dados", \
	 "Introdução"]

	pickle.dump (dicionario, pickle_file, protocol=pickle.HIGHEST_PROTOCOL)
	pickle_file.close()

def read_file ():
	"""Le o dicionario do arquivo"""
	pickle_file = open ("pickle1.dat", "rb")
	dicionario = pickle.load (pickle_file)
	pickle_file.close()

	for course in dicionario:
		print (dicionario.index (course), "-", course)

def delete_file ():
	"""Deleta uma entrada do dicionario"""
	deletar = int (input("Qual entrada voce quer deletar? "))
	pickle_file = open ("pickle1.dat", "rb")
	dicionario = pickle.load (pickle_file)
	pickle_file.close()

	try:
		dicionario.pop (deletar)
		pickle_file = open ("pickle1.dat", "wb")
		pickle.dump (dicionario, pickle_file, protocol= pickle.HIGHEST_PROTOCOL)
		pickle_file.close()
	except:
		print ("Nao existe essa entrada")

def add_record ():
	"""Adiciona um registro ao dicionario.
	Tambem atualiza o arquivo"""

	pickle_file = open ("pickle1.dat", "rb")
	dicionario = pickle.load (pickle_file)
	dicionario.append ("SQL Programming")
	dicionario.append ("Database Programming")
	pickle_file.close()

	pickle_file = open ("pickle1.dat", "wb")
	pickle.dump (dicionario, pickle_file, protocol=pickle.HIGHEST_PROTOCOL)
	print ("Adicionado uma nova entrada")
	pickle_file.close()

def display_instructions ():
	"""Display the Main menu"""
	print( \
		"""
		Menu Principal:
		1. Exit
		2. Cria um arquivo
		3. Adicionar mais cursos
		4. Ler o arquivo
		5. Deletar entrada
		6. Mostrar informações
		""")
def over_program ():
	"""Sair do programa"""
	print ("Adeus")

def main ():
	choice = None
	display_instructions ()

	while choice != 1:
		choice = input ("\nChoice: ")
		if choice == "1":
			over_program()
			break

		elif choice == "2":
			write_file ()

		elif choice == "3":
			add_record ()

		elif choice == "4":
			read_file ()

		elif choice == "5":
			delete_file ()
			
		elif choice == "6":
			display_instructions ()

		else:
			print ("\n Digite outro numero")


main()
print ("Press Enter Key to exit.")
