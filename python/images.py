from bs4 import BeautifulSoup
import urllib.parse
import urllib.request
from urllib.request import urlopen, Request
import typing as tp
URL = "https://yandex.ru/images/"

def download_images(url: str, num: int) -> tp.List[str]:
    """
    Download images from given url
    params: url - from where to download images
            num - number of images to download
    return: List of images' descriptions
    """
    requester = {'User-Agent': 'Mozilla/5.0'}
    req=Request(url, headers=requester)
    u = urlopen(req)


    soup = BeautifulSoup(u.read(), features="lxml")
    names = []
    for index, img in enumerate(soup.findAll('img')):
        if index and index <= num:
            urllib.request.urlretrieve(img.get("src"), "image" + str(index) + ".jpg")
            names.append(img.get("alt"))
    return names