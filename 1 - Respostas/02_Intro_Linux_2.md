# 1. Escreva o texto "Ola mundo cruel!" em um arquivo denominado "Ola_mundo.txt". Apresente o conteúdo deste arquivo no terminal.

echo Ola mundo cruel! > Ola_mundo.txt	

   cat Ola_mundo.txt

# 2. Apresente o nome de todos os arquivos e pastas na pasta 'root'.

   após entrar como super usuário, digite o comando:
   
   ls -la /root/

# 3. Apresente o tipo de todos os arquivos e pastas na pasta 'root'.

   após entrar como super usuário, digite o comando:
   
   file -l /root/

# 4. Apresente somente as pastas dentro da pasta 'root'.

   ls /root/ | grep "/"

# 5. Descubra em que dia da semana caiu o seu aniversário nos últimos dez anos

???

Para as questões a seguir, use a pasta no endereço https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Questoes/02_Intro_Linux_arqs.zip

# 6. Liste somente os arquivos com extensão .txt.

   ls *.txt

# 7. Liste somente os arquivos com extensão .png.

   ls *.txt

# 8. Liste somente os arquivos com extensão .jpg.

   ls *.jpg

# 9. Liste somente os arquivos com extensão .gif.

   ls *.gif

# 10. Liste somente os arquivos que contenham o nome 'cal'.

   ls *cal*

# 11. Liste somente os arquivos que contenham o nome 'tux'.

   ls *tux*

# 12. Liste somente os arquivos que comecem com o nome 'tux'.

   ls tux*
