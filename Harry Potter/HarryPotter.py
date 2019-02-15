amounts = [0, 0, 0]
cost = 0

amounts[0] = int(input("First Book: "))
amounts[1] = int(input("Second Book: "))
amounts[2] = int(input("Third Book: "))

triples = min(amounts)
cost += 21.6 * triples
amounts.remove(min(amounts))
amounts = [i - triples for i in amounts]

doubles = min(amounts)
cost += 15.2 * doubles
amounts.remove(min(amounts))
amounts = [i - doubles for i in amounts]

cost += 8 * amounts[0]

print(cost)



# books = [1, 2, 3]
# for i in range(0, len(books)):
#     if (books[i] == 1):
#         amounts[0] += 1
#     elif (books[i] == 2):
#         amounts[1] += 1
#     elif (books[i] == 3):
#         amounts[2] += 1