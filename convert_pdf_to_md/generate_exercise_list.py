import requests
import re
from bs4 import BeautifulSoup
from collections import defaultdict
import html as h

r = requests.get("https://a2oj.com/categories")
html = r.text
parsed_html = BeautifulSoup(html, 'lxml')
desc = parsed_html.findAll(attrs={"class": re.compile(r'odd', re.I)})

is_name = re.compile(r'>(.*?)<')
is_category = re.compile(r'\=\"(.*?)\"')
is_digit = re.compile(r'\d+')
not_only_numbers = re.compile(r'[^\W\d_]', re.U)

d = defaultdict(lambda: (0, 0))
id = defaultdict(lambda: 0)
for i in range(0, len(desc)):
    nm = str(list(desc[i])[3])
    ct = str(list(desc[i])[5])
    category_names = (is_name.findall(nm)[1]).lower().split(' ')
    category_id = is_category.findall(nm)[0]
    category_count = int(is_digit.findall(ct)[0])
    for name in category_names:
        html_correct = h.unescape(name)
        symbol_correct = ''.join(e for e in html_correct if e.isalnum())
        if not_only_numbers.search(symbol_correct) and len(symbol_correct) > 1:
            id[symbol_correct] += 1
            d[symbol_correct+str(id[symbol_correct])] = (category_count, category_id)

category_count = open("category_count.txt", 'w')

for key, value in d.items():
    if value[0] > 0:
        category_count.write(key+' '+str(value[0])+' '+str(value[1])+'\n')

category_count.close()
