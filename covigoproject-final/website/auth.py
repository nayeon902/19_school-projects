from flask import Blueprint, render_template, request, flash, redirect, url_for,jsonify
from flask_login import login_user, login_required, logout_user, current_user
from werkzeug.security import generate_password_hash, check_password_hash
from .models import User,Way
from sqlalchemy.sql import func
from bs4 import BeautifulSoup
import requests
from . import db
import time

auth = Blueprint('auth', __name__)

@auth.route("/checkmap.html",methods=['GET','POST'])
def checkmap():
    currenttime=time.strftime('%c', time.localtime(time.time()))
    return render_template("checkmap.html",currenttime=currenttime)
@auth.route("/corona.html",methods=['GET','POST'])
def corona():
    currenttime=time.strftime('%c', time.localtime(time.time()))
    return render_template("corona.html",currenttime=currenttime)

@auth.route("/map.html",methods=['GET','POST'])
def map(): 
    #CamAPI = 'https://172.22.96.1/myapp/detectObjects'
    #StoreSize = 'https://220.119.156.6/storesize'
    #try:
    #    PersonCouter = requests.get(CamAPI).json() #uResponse == dict 이렇게 받으면 딕셔너리 형태 
    #    #StoreSize = requests.get(StoreSize).json()
    #except requests.ConnectionError: 
    #    return "Connection Error"
    #Jresponse = ResponseOFLevel.text   #jresponse는 한글 api 화 , data는 한글 변환 전 
    #data = jsonify(JsonResponse) #딕셔너리화
    #personCount = 0
    #for i in len(PersonCouter['labels']):
    #  person = PersonCouter["detections"]['labels'][i]['label'] 
    #  if person is 'person':
     #     personCount += 1
    #global SafetyLevel
    # 매장 안전도는?
    #SafetyLevel =personCount/StoreSize *0.01 
    return render_template("map.html")
    
@auth.route("/corona.html",methods=['GET', 'POST'])
def GetWays():
    if request.method =='POST':
        global where
        where = request.form.get('placeway')
        u= Way(where= where,user_id=current_user)
        db.session.add(u)
        db.session.commit()
        flash('The location of the visit was recorded!')
        #way =   #User의 정보를 확인하기
        return render_template("corona.html")
        
    

@auth.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        email = request.form.get('email')
        password = request.form.get('password')

        user = User.query.filter_by(email=email).first()
        if user:
            if check_password_hash(user.password, password):
                flash('Logged in successfully!', category='success')
                login_user(user, remember=True)
                return redirect(url_for('views.home'))
            else:
                flash('Incorrect password, try again.', category='error')
        else:
            flash('Email does not exist.', category='error')

    return render_template("login.html", user=current_user)


@auth.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('auth.login'))


@auth.route('/sign-up', methods=['GET', 'POST'])
def sign_up():
    if request.method == 'POST':
        email = request.form.get('email')
        first_name = request.form.get('firstName')
        password1 = request.form.get('password1')
        password2 = request.form.get('password2')

        user = User.query.filter_by(email=email).first()  
        if user:
            flash('Email already exists.', category='error')
        elif len(email) < 4:
            flash('Email must be greater than 3 characters.', category='error')
        elif len(first_name) < 2:
            flash('First name must be greater than 1 character.', category='error')
        elif password1 != password2:
            flash('Passwords don\'t match.', category='error')
        elif len(password1) < 7: 
            flash('Password must be at least 7 characters.', category='error')
        else:
            new_user = User(email=email, first_name=first_name, password=generate_password_hash(
                password1, method='sha256'))
            db.session.add(new_user)
            db.session.commit()
            login_user(new_user, remember=True)
            flash('Account created!', category='success')
            return redirect(url_for('views.home')) 

    return render_template("sign_up.html", user=current_user)