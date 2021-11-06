# -*- coding:utf-8 -*-

import os
import io
import re
import easygui as g

# easyguiのdiropenbox関数でフォルダを選択して、そのフォルダのアドレスをpathに渡す
path = g.diropenbox("コードのフォルダーを選択してください", "フォルダー選択")
print(path)

# pathの中のファイルかフォルダをリスト化する
a = os.listdir(path)
print(a)

# 各言語のコードの行数とファイル数を統計する数値を初期化する
count_py = 0  # python行数
count_py_num = 0  # pythonファイル数
count_c = 0  # c行数
count_c_num = 0  # cファイル数
count_cpp = 0  # cpp行数
count_cpp_num = 0  # cppファイル数
count_java = 0  # java行数
count_java_num = 0  # javaファイル数
count_html = 0  # html行数
count_html_num = 0  # htmlファイル数
count_css = 0  # css行数
count_css_num = 0  # cssファイル数
count_js = 0  # js行数
count_js_num = 0  # jsファイル数

count_command = {}


def count(a,path):
    for name in a:
        file = path + "/" + name
        if file[-3:] == ".py":
            # リストaの中の要素を一つずつ見て、拡張子でどの言語で書かれているかを判別する。そして、ある言語のファイルを見つけ出せたら、count_(その言語の拡張子)_numがプラス１する。次に、ファイルの中身の行数を数えてcount_pyの中に入れる。
            global count_py_num
            count_py_num += 1
            f = open(file, 'rb')
            global count_py
            count_py += len(list(f))

            # 何らかの原因でファイルの中の文字が読み取れない場合にも、それをパスして実行し続ける
            try:
                with io.open(file, 'r', encoding="utf-8") as f:
                    text = f.read()
            except:
                pass

            # そして、ファイルを文字列として読み取り、文字以外の物（スペース、符号など）で文字列をsplitしてsplitlineにリストとして入れる
            # そして、splitlineの中の数字を削除する。次に、一番よく出る命令を見つけ出すため、リスト中の単語を辞書count_commandの中に入れる
            splitline = re.split("\W+", text)
            for elem in splitline:
                if re.match(r'[0-9]+', elem):
                    elem = "UKN"
                # splitline.remove(elem)
                if elem not in count_command:
                    count_command[elem] = 1
                elif elem in count_command:
                    count_command[elem] += 1

        if file[-2:] == ".c":
            global count_c_num
            count_c_num += 1
            f = open(file, 'rb')
            global count_c
            count_c += len(list(f))
            try:
                with io.open(file, 'r', encoding="utf-8") as f:
                    text = f.read()
            except:
                pass

            splitline = re.split("\W+", text)
            for elem in splitline:
                if re.match(r'[0-9]+', elem):
                    elem = "UKN"
                if elem not in count_command:
                    count_command[elem] = 1
                elif elem in count_command:
                    count_command[elem] += 1

        if file[-4:] == ".cpp":
            global count_cpp_num
            count_cpp_num += 1
            f = open(file, 'rb')
            global count_cpp
            count_cpp += len(list(f))
            try:
                with io.open(file, 'r', encoding="utf-8") as f:
                    text = f.read()
            except:
                pass

            splitline = re.split("\W+", text)
            for elem in splitline:
                if re.match(r'[0-9]+', elem):
                    elem = "UKN"
                if elem not in count_command:
                    count_command[elem] = 1
                elif elem in count_command:
                    count_command[elem] += 1

        if file[-5:] == ".java":
            global count_java_num
            count_java_num += 1
            f = open(file, 'rb')
            global count_java
            count_java += len(list(f))
            try:
                with io.open(file, 'r', encoding="utf-8") as f:
                    text = f.read()
            except:
                pass

            splitline = re.split("\W+", text)
            for elem in splitline:
                if re.match(r'[0-9]+', elem):
                    elem = "UKN"
                if elem not in count_command:
                    count_command[elem] = 1
                elif elem in count_command:
                    count_command[elem] += 1

        if file[-5:] == ".html":
            global count_html_num
            count_html_num += 1
            f = open(file, 'rb')
            global count_html
            count_html += len(list(f))
            try:
                with io.open(file, 'r', encoding="utf-8") as f:
                    text = f.read()
            except:
                pass

            splitline = re.split("\W+", text)
            for elem in splitline:
                if re.match(r'[0-9]+', elem):
                    elem = "UKN"
                if elem not in count_command:
                    count_command[elem] = 1
                elif elem in count_command:
                    count_command[elem] += 1

        if file[-4:] == ".css":
            global count_css_num
            count_css_num += 1
            f = open(file, 'rb')
            global count_css
            count_css += len(list(f))
            try:
                with io.open(file, 'r', encoding="utf-8") as f:
                    text = f.read()
            except:
                pass

            splitline = re.split("\W+", text)
            for elem in splitline:
                if re.match(r'[0-9]+', elem):
                    elem = "UKN"
                if elem not in count_command:
                    count_command[elem] = 1
                elif elem in count_command:
                    count_command[elem] += 1

        if file[-3:] == ".js":
            global count_js_num
            count_js_num += 1
            f = open(file, 'rb')
            global count_js
            count_js += len(list(f))
            try:
                with io.open(file, 'r', encoding="utf-8") as f:
                    text = f.read()
            except:
                pass

            splitline = re.split("\W+", text)
            for elem in splitline:
                if re.match(r'[0-9]+', elem):
                    elem = "UKN"
                if elem not in count_command:
                    count_command[elem] = 1
                elif elem in count_command:
                    count_command[elem] += 1

        if("." not in file):
            a = os.listdir(file)
            count(a,path+"/"+name)

count(a,path)

# 各拡張子の行数をsum_countに入れる
sum_count = count_py+count_c+count_cpp+count_java+count_html+count_css+count_js
# sum_countが100000を占める割合をpersentに入れる
persent = sum_count/100000*100

# 画面化して、各変数を表示する
g.textbox(msg="今まで{0}行のコードを書き上げました。進み具合：{1}%\n10万行コードまで後{2}行，頑張り続けてください！".format(sum_count, persent, 100000-sum_count), title="コード行数統計結果",
          text="[.py]ファイル%d個,コード%d行\n[.c]ファイル%d個,コード%d行\n[.cpp]ファイル%d個,コード%d行\n[.java]ファイル%d個,コード%d行\n[.html]ファイル%d個,コード%d行\n[.css]ファイル%d個,コード%d行\n[.js]ファイル%d個,コード%d行\n" % (count_py_num, count_py, count_c_num, count_c, count_cpp_num, count_cpp, count_java_num, count_java, count_html_num, count_html, count_css_num, count_css, count_js_num, count_js))

# 辞書count_commandをvalueで昇順でソートして、プリントする
count_word = sorted(count_command.items(), key=lambda x: x[1])

# 目的はコマンドをコマンドのランキングを作るということなので、絶対にコマンドではないやつを除いて、コマンドだけをプリントする。
for word in count_word:
    if len(word[0]) >= 2 and word[0] != 'UKN':
        print(word)
