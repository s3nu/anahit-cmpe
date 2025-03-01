from html.parser import HTMLParser  
from urllib.request import urlopen  
from urllib import parse

class LinkParser (HTMLParser):
	
	def handle_starttag(self, tag, attrs):
		if tag == 'a':
			for (key, value) in attrs:
				if key=='href':
					newUrl = parse.urljoin(self.baseUrl, value)
					self.links = self.links + [newUrl]

	def getLinks(self, url):
		self.links = []
		self.baseUrl = url
		response = urlopen(url)
		if response.getheaders ('Content-Type')=='text/html':
			htmlBYtes =  response.read()
			htmlString = htmlBytes.decode("utf-8")
			self.feed(htmlString)
			return htmlString, self.links
		else:
			return "",[]

def hunt(url, word, maxPages):
	Visit_Future = [url]
	Visit_Number = 0
	foundWord = False
	while Visit_Number < maxPages and Visit_Future != [] and not foundWord:
		Visit_Number= Visit_Number + 1
		url = Visit_Future[0]
		Visit_Future = Visit_Future[1:]
		try:
			print(Visit_Number, "Hunting", url)
			parser = LinkParser()
			data, links = parser.getlinks(url)
			if data.find(word)>-1:
				pagesToVisit = pasgesToVisit + links
				print(" **Success!**")
		except: 
			print("Failer to find Word")
	if foundWord:
		print("Chached:", word,"root:", url)
	else:
		print("BlackList:", word,", root:", url)

#Link Into local Int-python 
#	Python 3.5.1 (default, Jan 22 2016, 17:08:33) 
#	[GCC 4.2.1 Compatible Apple LLVM 6.0 (clang-600.0.57)] on darwin
#	#exec(open('./webC.py').read())
