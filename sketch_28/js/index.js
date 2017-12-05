var dataurl="https://newsapi.org/v2/top-headlines?sources=associated-press,bbc-news,al-jazeera-english,bloomberg,breitbart-news,cnn,buzzfeed,el-mundo,fox-news,google-news,independent,politico,newsweek,nbc-news,new-york-magazine,the-hill,%20the-new-york-times,the-washington-post,vice-news,the-telegraph&apiKey=2a2dd30b2a2045dba5367cc019c8a54d";

var headlines =[];

$.getJSON(dataurl, function(data){
  // console.log(JSON.stringify(data));
  // var titles=[];  
  // console.log(data["articles"].length);
  for(var i = 0; i < data["articles"].length; i++){
    headlines.push([data["articles"][i].title,data["articles"][i].author]);
  }
  // console.log(titles, '!')
  // return titles;
  // var titles = [];
  // for(var  i = 0; i<data.length; i ++){
  // }
  // return "hi";
});

const app = new Vue({
  el: "#app",
  methods:{
    randomNews: function(){
      const index = Math.floor(Math.random() * headlines.length);
      this.title=headlines[index][0];
      this.author=headlines[index][1];
    }

  },
  data:{
    message: headlines[0],
    title: "",
    author: "",
    // message: title
  }
})