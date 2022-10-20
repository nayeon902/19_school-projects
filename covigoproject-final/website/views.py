from flask import Blueprint, render_template, request, flash, jsonify
from flask_login import login_required, current_user
from .models import Note
import requests
from . import db
import json

views = Blueprint('views', __name__)


@views.route('/', methods=['GET', 'POST'])
@login_required
def home():
    url = 'https://api.odcloud.kr/api/15089317/v1/uddi:23f5d02f-0047-46c8-a938-defadc2ab47c?page=1&perPage=10&serviceKey=W49e4Wr90U5DXjGJyKqx8ZN6YgMlYhAO63tvSt8KDqhAX3IErW0wxqBkfAxF1CPWmLmULaaOux9JZwcIYp57Rw%3D%3D'
    url2 = 'https://api.corona-19.kr/korea/?serviceKey=tzpA3J2VhGXBQ98jOgkC5E7wbSarnUKeo'
    try:
        ResponseOFLevel = requests.get(url).json() #uResponse == dict
        ResponseOFCount =requests.get(url2).json()
       # JsonResponse = json.dumps(ResponseOFLevel) #JsonResponse ==str
    except requests.ConnectionError: 
        return "Connection Error"
    #Jresponse = ResponseOFLevel.text   #jresponse는 한글 api 화 , data는 한글 변환 전 
    #data = jsonify(JsonResponse) #딕셔너리화
    data = ResponseOFLevel["data"] 
    TotalDeath = ResponseOFCount['TotalDeath']
    TotalCase = ResponseOFCount['TotalCase']
    TotalRecovered = ResponseOFCount['TotalRecovered']
    CoronaLevel = data[1]['거리 두기 단계'] #딕셔녀리 
    Region =  data[1]['시도명'] #파이썬에서 출력하면 한글로 나오고 jsonify하면 유니코드로 나옴. 
    Whenisit = data[0]['기준일시'] 

    return render_template("home.php",CoronaLevel = CoronaLevel,Region=Region,Whenisit=Whenisit,TotalDeath=TotalDeath, TotalCase=TotalCase,TotalRecovered=TotalRecovered)

@views.route('/yay', methods=['GET', 'POST'])
def home2():
    url = 'https://api.odcloud.kr/api/15089317/v1/uddi:23f5d02f-0047-46c8-a938-defadc2ab47c?page=1&perPage=10&serviceKey=W49e4Wr90U5DXjGJyKqx8ZN6YgMlYhAO63tvSt8KDqhAX3IErW0wxqBkfAxF1CPWmLmULaaOux9JZwcIYp57Rw%3D%3D'
    url2 = 'https://api.corona-19.kr/korea/?serviceKey=tzpA3J2VhGXBQ98jOgkC5E7wbSarnUKeo'
    try:
        ResponseOFLevel = requests.get(url).json() #uResponse == dict
        ResponseOFCount =requests.get(url2).json()
       # JsonResponse = json.dumps(ResponseOFLevel) #JsonResponse ==str
    except requests.ConnectionError: 
        return "Connection Error"
    #Jresponse = ResponseOFLevel.text   #jresponse는 한글 api 화 , data는 한글 변환 전 
    #data = jsonify(JsonResponse) #딕셔너리화
    data = ResponseOFLevel["data"] 
    TotalDeath = ResponseOFCount['TotalDeath']
    TotalCase = ResponseOFCount['TotalCase']
    TotalRecovered = ResponseOFCount['TotalRecovered']
    CoronaLevel = data[1]['거리 두기 단계'] #딕셔녀리 
    Region =  data[1]['시도명'] #파이썬에서 출력하면 한글로 나오고 jsonify하면 유니코드로 나옴. 
    Whenisit = data[0]['기준일시'] 

    return render_template("home2.php",CoronaLevel = CoronaLevel,Region=Region,Whenisit=Whenisit,TotalDeath=TotalDeath, TotalCase=TotalCase,TotalRecovered=TotalRecovered)


@views.route('/delete-note', methods=['POST'])
def delete_note():
    note = json.loads(request.data)
    noteId = note['noteId']
    note = Note.query.get(noteId)
    if note:
        if note.user_id == current_user.id:
            db.session.delete(note)
            db.session.commit()

    return jsonify({})
  
