#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import sys
import time
import urllib
import urllib.parse
import urllib.request
import queue
import re

def get(url, **kwargs):
  if kwargs:
    data = urllib.parse.urlencode(kwargs) 
    request = urllib.request.Request(url, data.encode())
  else:
    request = urllib.request.Request(url)

  request.add_header('User-Agent', 'bug.py/0.1')

  response = urllib.request.urlopen(request)
  return response.read()

def processIciba(word):
  regex = re.compile('<div class=\'word-rate\'>\s*<p>(<i( class=\'light\')?></i>)(<i( class=\'light\')?></i>)(<i( class=\'light\')?></i>)(<i( class=\'light\')?></i>)(<i( class=\'light\')?></i>)</p>\s*</div>')
  
  html = ''
  try:
    html = get('http://www.iciba.com/' + word).decode()
  except Exception as err:
    print(err)

  m = regex.search(html)
  
  if m:
    c = sum([1 if g == ' class=\'light\'' else 0 for g in m.groups()])
    return c
  else:
    return None

def processDictcn(word):
  regex = re.compile('class="level_(?P<level>\d)"')
  
  html = ''
  try:
    html = get('http://dict.cn/' + word).decode()
  except Exception as err:
    print(err)

  m = regex.search(html)

  if m:
    return int(m.groups('level')[0])
  else:
    return None

processors = {'iciba': processIciba, 'dictcn': processDictcn}

def main():
  words = []
  level = {}
  
  with open('dict.txt', 'rt') as f:
   words = [line.split(',')[0] for line in f]
  
  print(words)
  
  for word in words:
    level[word] = {}
    for k in processors:
      level[word][k] = processors[k](word)
    print(word, level[word])
  
  for k in processors:
    with open(k + '_level.txt', 'wt') as f:
      for word in level:
        f.write('{0}, {1}\n'.format(word, level[word][k]))

if __name__ == '__main__':
    main()
