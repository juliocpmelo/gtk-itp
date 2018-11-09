
if [ "$#" -ne 1 ]; then
	echo "Número errado de argumentos, use ./createProj.sh <nome_projeto>"
else
	mkdir $1
	cp -r template/src $1
	cp -r template/glade $1
	cp template/Makefile $1
fi
