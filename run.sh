make
# 1st argument -- population size
# 2nd argument -- genetic representation size
# 3rd argument -- necessary when using Clercs for particle movement 
# 4th argument -- necessary when using Clercs for particle movement 
# 5th argument -- number of runs

popsize=20
repsize=26
runs=50
#i=1
#j=1
#k=1

#while [ $i -le 5 ] # controls population size
#do
		#j=1
		#mutrate=0
		#while [ $j -le 6 ] # controls mutation rate
		#do
				#k=1
				#while [ $k -le 10 ] #repitious runs for statistical significance
				#do
						./test $popsize $repsize $runs > rmess.txt #R050105-$popsize-$mutrate-$evals-$k.txt
						#k=`expr $k + 1` # increment k
				#done

				#j=`expr $j + 1` # increment j
				#mutrate=`expr $mutrate + 2`
		#done

		#i=`expr $i + 1` # increment i
		#popsize=`expr $popsize + 10`
#done

#rm test
#make clean
