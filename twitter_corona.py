#This code creates the dataset from Corpus.csv which is downloadable from the
#internet well known dataset which is labeled manually by hand. But for the text
#of tweets you need to fetch them with their IDs.
import tweepy

# Twitter Developer keys here
# It is CENSORED
consumer_key = 'vzkVupmn3UaZYMDFmus46WboQ'
consumer_key_secret = 'x98yyMJrUxf8uuSjh2dutpEvCwnkFcqiS9plfj5mbXDSclRXuA'
access_token = '3737898144-n0ihrxBS8SEEtfyjkGocmtrGpND7eIWZxXZy3W0'
access_token_secret = 'dTFqbZG9R6ejLyN49Dxgc72BI80G1j60VQJkCib00cTEZ'

auth = tweepy.OAuthHandler(consumer_key, consumer_key_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)

# This method creates the training set
def createTrainingSet(corpusFile, targetResultFile):
    import csv
    import time

    corpus = []

    with open(corpusFile, 'r') as csvfile:
        lineReader = csv.reader(csvfile, delimiter='\t', quotechar="\"")
        for row in lineReader:
            print(row)
            corpus.append({"tweet_id": row[1], "keyword": row[2], "time": row[0]})

    sleepTime = 0
    trainingDataSet = []

    for tweet in corpus:
        try:
            tweetFetched = api.get_status(tweet["tweet_id"])
            print("Tweet fetched:" + tweetFetched.text)
            tweet["text"] = tweetFetched.text
            tweet["user_name"]=tweetFetched.user.name
            trainingDataSet.append(tweet)
            time.sleep(sleepTime)
              
        except:
            print("Inside the exception - no:2")
            continue

    with open(targetResultFile, 'a') as csvfile:
        linewriter = csv.writer(csvfile, delimiter=',', quotechar="\"")
        for tweet in trainingDataSet:
            try:
                linewriter.writerow([tweet["tweet_id"], tweet["text"], tweet["time"],tweet["user_name"],tweet["keyword"],'\n'])
            except Exception as e:
                print(e)
    return trainingDataSet

# Code starts here
# This is corpus dataset
corpusFile = "/Users/zhangyiyang/Desktop/毕业论文相关/2020-04-01_en.tsv"
# This is my target file
targetResultFile = "/Users/zhangyiyang/Desktop/毕业论文相关/2020-04-01_en_extraction.csv"
# Call the method
resultFile = createTrainingSet(corpusFile, targetResultFile)