
<!doctype html>
<html lang="en"> 
{% extends "base.html" %} {% block title %}Home{% endblock %} {% block content%}
<body>
  
<br>
<h1 align="center">COVID-GO</h1>

<main class="container">
 
  <div class="pricing-header px-3 py-3 pt-md-5 pb-md-4 mx-auto text-center">
       <p class="lead">코로나바이러스감염증(코로나19)은 새롭게 발견된 코로나바이러스로 인해 발생하는 감염 질환입니다.
코로나19에 감염되면 대부분 경증에서 중증 수준의 증상을 보이며 특별한 치료 없이도 질환으로부터 회복합니다. 현재 2021-11-6 을 확인하고 있습니다.</p>
  </div>
<style>
@import url('https://fonts.googleapis.com/css2?family=Nanum+Gothic+Coding:wght@400;700&family=Play:wght@700&display=swap');
@import url('https://fonts.googleapis.com/css2?family=Nanum+Gothic:wght@800&display=swap');

  h1{
    color: #191970;
    font-family: 'Play', sans-serif;
    font-size: 72px;
  }
  h2{
    font-family: 'Nanum Gothic', sans-serif;
     text-align: center;
  }
  ul.mylist li:before,
  ol.mylist li:before {
    content: ">";
    display: inline-block;
    vertical-align: middle;
    padding: 0px 5px 6px 0px;
  }
  ul.mylist li, ol.mylist li {
    list-style: none;
    padding: 5px 0px 5px 5px;
    margin-bottom: 5px;
    border-bottom: 1px solid #efefef;
    font-size: 24px;
    font-family: 'Nanum Gothic Coding', monospace;
  }
  .line1{
    width:80%;
    height:40px;
    border-radius:5%;
    background:#00d3d3;
    
  }
  .line2{
    width:10%;
    height:20%;
    border-radius:5%;
    background:#00d3d3;
    
  }

  .rounded1 {
  background: #F3C136;
  height: 50px; width: 190px;
  border-radius: 30px;
  padding: 10px 0;
  font-family: 'Nanum Gothic', sans-serif;
  text-align:center;
   position: absolute;
    top: 95px;
    left: 220px;
}
.rounded2 {
  background: #DEDCD8;
  height: 50px; width: 180px;
  border-radius: 30px;
  padding: 10px 0;
  font-family: 'Nanum Gothic', sans-serif;
  text-align:center;
   position: absolute;
    top: 200px;
    left: 800px;
}
.rounded3 {
  color:white;
  background: black;
  height: 50px; width: 180px;
  border-radius: 30px;
  padding: 10px 0;
  font-family: 'Nanum Gothic', sans-serif;
  text-align:center;
   position: absolute;
    top: 200px;
    left: 450px;
}
.rounded4 {
  background: #81E867;
  height: 50px; width: 220px;
  border-radius: 30px;
  padding: 10px 0;
  font-family: 'Nanum Gothic', sans-serif;
  text-align:center;
   position: absolute;
    top: 320px;
    left: 330px;
}
 .mapbutton{
    color:white;
    background: #050099;
  height: 50px; width: 190px;
  border-radius: 30px;
  padding: 10px 0;
  font-family: 'Nanum Gothic', sans-serif;
  text-align:center;
  position: absolute;
    top: 500px;
    left: 470px;
  }
</style>
<h5>거리두기 단계 기준 시도명: {{ Region }}</h5>
 <div class="level text-center">
      <div class="card mb-3 shadow-sm">
      <div class="card-header">
        <h4 class="my-0 fw-normal" >거리두기 단계</h4>
      </div>
      <div class="card-body">
        <h1 class="card-title pricing-card-title">{{ CoronaLevel }} <small class="text-muted">단계</small></h1>
      </div>
    </div>
    </div>
 <div class="row row-cols-1 row-cols-md-3 mb-3 text-center">
    <div class="col">
      <div class="card mb-3 shadow-sm">
      <div class="card-header">
        <h4 class="my-0 fw-normal">국내 확진자</h4>
      </div>
      <div class="card-body">
        <h2 class="card-title pricing-card-title">{{ TotalCase }} <small class="text-muted">명</small></h2>
      </div>
    </div>
  </div>
    <div class="col">
      <div class="card mb-3 shadow-sm">
      <div class="card-header">
        <h4 class="my-0 fw-normal">국내 완치자</h4>
      </div>
      <div class="card-body">
        <h2 class="card-title pricing-card-title">{{ TotalRecovered }}<small class="text-muted">명</small></h2>
      </div>
    </div>
    </div>
    <div class="col">
      <div class="card mb-3 shadow-sm">
      <div class="card-header">
        <h4 class="my-0 fw-normal">국내 사망자</h4>
      </div>
      <div class="card-body">
        <h2 class="card-title pricing-card-title">{{ TotalDeath }} <small class="text-muted">명</small></h2>
      </div>
    </div>
    </div>
</div>
  <footer class="pt-4 my-md-5 pt-md-5 border-top">
    <div class="row">
      
</main>
 
<div class="card mb-3 shadow-sm">
  <div class="card-body">
    <h2>최근 방문 장소</h2>
    <br>
   <ul class="mylist">
        <li ></li>
        <li ></li>
        <li ></li>
        <li></li>
    
       
    </ul>   
  </div>
</div>

<div class="card mb-3 shadow-sm">
  <div class="card-body">
   <h2>추천 방문 경로</h2>
   <br>
   <br>
      <canvas id="myCanvas" style="background-color:white"
     width="1050" height="500"></canvas>
  <script>
    var canvas = document.getElementById("myCanvas");
    var context = canvas.getContext("2d");
    
    // 1 픽셀의 blue 직선 그리기
    context.beginPath();
    context.moveTo(20, 20);
    context.lineTo(1000, 20);
    context.strokeStyle = "#F90A61";
    context.lineWidth = 40;
    context.stroke(); 

    context.beginPath();
    context.moveTo(1000, 0);
    context.lineTo(1000, 130);
    context.strokeStyle = "#F9B10A";
    context.lineWidth = 40;
    context.stroke(); 

    context.beginPath();
    context.moveTo(1020, 130);
    context.lineTo(20, 130);
    context.strokeStyle = "#5B50EE";
    context.lineWidth = 40;
    context.stroke(); 

    context.beginPath();
    context.moveTo(35,110);
    context.lineTo(35,250);
    context.strokeStyle = "#6EC02F";
    context.lineWidth = 40;
    context.stroke(); 

    context.beginPath();
    context.moveTo(15,250);
    context.lineTo(1015,250);
    context.strokeStyle = "black";
    context.lineWidth = 40;
    context.stroke(); 
  //도형
  //
   
    </script>
   
<button type="button" class='rounded1' onclick="location.href='map.html'">스타벅스 김해 내동점</button>
<button type="button" class='rounded2' onclick="location.href='map.html'">아웃백 김해점</button>
<button type="button" class='rounded3' onclick="location.href='map.html'">CU김해 내동점</button>
<button type="button" class='rounded4' onclick="location.href='map.html'">르하임 스터디 카페 내동점</button>
<div><button type="button" class='mapbutton' onclick="location.href='map.html'">CoronaMap</button></div>
</body>
{% endblock %}
</html>
