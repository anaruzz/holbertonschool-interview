#!/usr/bin/python3
"""
A function that queries the Reddit API, parses the title
of all hot articles, and prints a sorted count of given keywords
"""
import requests as rq
import sys
import json


def recursive(subreddit, hot_list=[]):
    """
    Returns a list with the titles of all hot articles
    """
    try:
        url = 'https://www.reddit.com/r/'
        global after
        if after:
            response = rq.get(url + subreddit + "/hot.json?after=" +
                                    after, headers=headers,
                                    allow_redirects=False)
        else:
            response = rq.get(url + subreddit + "/hot.json",
                                    headers=headers, allow_redirects=False)
        after = response.json()['data']['after']
        hot_list += [element['data']['title'] for element in response.
                     json()['data']['children']]
        if after:
            return recursive(subreddit, hot_list)
        return hot_list
    except Exception:
        return None


def count_words(subreddit, word_list):
    """
    parses the title of all hot articles, and prints a sorted
    count of given keywords
    """
    global headers
    headers = {
        'User-Agent': 'My User Agent 1.0'
    }
    global after
    after = None
    hot_list = recursive(subreddit, hot_list=[])
    if hot_list is None:
        return

    occ = {word: 0 for word in word_list}

    for title in hot_list:
        title = title.lower().split()
        for w in word_list:
            for t in title:
                if w.lower() == t:
                    occ[w] += 1

    a_dict = sorted(occ.items(), key=lambda x: x[0])
    count_dict = sorted(a_dict, key=lambda x: x[1], reverse=True)

    for k, v in count_dict:
        if v != 0:
            print(k + ": " + str(v))
