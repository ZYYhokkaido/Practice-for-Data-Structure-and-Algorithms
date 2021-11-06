import csv

corpusFile = "/Users/zhangyiyang/Desktop/NLP/target.csv"
targetResultFile = "/Users/zhangyiyang/Desktop/NLP/extracted.csv"

corpus=[]

with open(corpusFile, 'r') as csvfile:
    lineReader = csv.reader(csvfile, delimiter=',')
    for row in lineReader:
        if("government" in row[1]):
            corpus.append({"tweet_id": row[0], "text": row[1], "time": row[2]})

with open(targetResultFile, 'w') as csvfile:
    linewriter = csv.writer(csvfile,delimiter=',')
    for tweet in corpus:
        try:
            linewriter.writerow([tweet["tweet_id"], tweet["text"], tweet["time"],'\n'])
        except Exception as e:
            print(e)




