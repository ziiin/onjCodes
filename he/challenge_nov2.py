# http://www.hackerearth.com/hotelsoft-hiring-challenge/algorithm/bowl-em-over-4/
# Unsolved
import sys


def f():
	t = int(raw_input())
	for i in range(t):
		row = sys.stdin.readline().split()
		final = 0
		count = 1
		l = len(row)
		#print "row", l
		i = 0
		adv = False
		while i < l:
			#print final
			# last chance case
			if count == 10:
				f = final
				if int(row[i]) == 10:
					final = final + int(row[i]) + int(row[i+1]) + int(row[i+2])
				elif int(row[i]) + int(row[i+1]) ==10:
					final = final + int(row[i]) + int(row[i+1]) + int(row[i+2])
				else:
					final = final + int(row[i]) + int(row[i+1])
				#print "last: Adding: ", final - f
				break
			# strike
			tmp_adv = False
			if int(row[i]) == 10:
				f = final
				tmp_adv = True
				if adv == True:
					final = final + int(row[i])
				final = final + int(row[i])
				i = i+1
				count = count+1
				adv = tmp_adv
				#print "Adding1", final -f, adv
				continue
			elif int(row[i]) + int(row[i+1]) ==10:
				f = final
				tmp_adv = True
				
				if adv == True:
					final = final + int(row[i]) + int(row[i+1])
				final = final + int(row[i]) + int(row[i+1])
				count = count+1
				adv = tmp_adv
				i = i+2
				#print "Adding2", final - f, adv
				continue
			else:
				f = final
				if adv == True:
					final = final + int(row[i]) + int(row[i+1])
				final = final + int(row[i]) + int(row[i+1])
				i = i+2
				count = count+1
				adv = tmp_adv
				#print "Adding3", final -f, adv
				continue
			
		print final

if __name__ == "__main__":
	f()
