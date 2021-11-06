import webbrowser
from weibopy import WeiboOauth2
from weibopy import WeiboClient
import csv
import re
import time

def main():
    '''
    if you want to use this api,you should follow steps follows to operate.
    '''
    try:
        # step 1 : sign a app in weibo and then define const app key,app srcret,redirect_url
        APP_KEY = '4236125587'
        APP_SECRET = '172b9455a650d9c41d5c1008b9a4150c'
        REDIRECT_URL = 'https://open.weibo.com/apps/4236125587/privilege/oauth'
        # step 2 : get authorize url and code
        client = WeiboOauth2(APP_KEY, APP_SECRET, REDIRECT_URL)
        url = client.authorize_url
        print(url)
        webbrowser.open_new(url)
        # step 3 : get Access Token
        # Copy the above address to the browser to run, 
        #enter the account and password to authorize, the new URL contains code
        result = client.auth_access(
            input("please input code : "))  # Enter the CODE obtained in the authorized address
        print(result)
        # At this point, the access_token and expires_in should be saved,
        # because there is a validity period.A
        # If you need to send the microblog multiple times in a short time,
        # you can use it repeatedly without having to acquire it every time.
        client=WeiboClient(result['access_token'])

        # step 4 : using api by access_token
        #print(client.public_timeline())  # get the latest public Weibo
        # =============================================================================
        #         statuses = client.public_timeline()['statuses']
        #         length = len(statuses)
        #         for i in range(0,length):
        #             print("昵称："+statuses[i]['user']['screen_name'])
        #             print("简介："+statuses[i]['user']['description'])
        #             print("位置："+statuses[i]['user']['location'])
        # =============================================================================
        '''
        in this step,the api name have to turn '/' in to '__'
        for example,statuses/public_timeline(this is a standard api name) have to turn into statuses__public_timeline
        '''
        # Or use this method

        corpusFile='/Users/zhangyiyang/Desktop/毕业论文相关/2020-04-01_en.tsv'
        goalFile='/Users/zhangyiyang/Desktop/毕业论文相关/2020-04-01_en_extraction.csv'

        # print(client.get(suffix='statuses/user_timeline.json'))
        with open(corpusFile, 'r') as tsvfile:
            lineReader = csv.reader(tsvfile, delimiter='\t', quotechar="\"")
            for row in lineReader:
                output=client.get(suffix='statuses/show.json',params={'id':row[1]})
                with open(goalFile,'a') as goal:
                    csv.writer(goal,delimiter=',',quotechar='\"').writerow([output['text'],output['created_at'],output['user']['screen_name'],output['id']])

        # print(client.get(suffix='statuses/user_timeline.json',params={'access_token':result['access_token']}))

        # Obtain the UID of the authorized user
        # print(client.account__get_uid())

    except ValueError:
        print('pyOauth2Error')

if __name__ == '__main__':
    main()