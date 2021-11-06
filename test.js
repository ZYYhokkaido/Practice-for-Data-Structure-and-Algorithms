


https://xx.com/zzz.mp3


on("data",function(chunk){
    //播放这部分
})


on("done",function(){
    //下载完了
})





//-------------------------------------------------------

subscribe("报纸到了",function(newspaper){
    //提醒我，我来取
})






//当歪卖送到你楼底下，给你发消息
emit("报纸到了",newspaper)
List<>


emit("停电了")



//--------------------------------------------------------

//do something
const handler = get("https://xxx.com/jay.mp3");     //async
//do other things
handler.on("done", function(mp3){
    mp3.play();
})
handler.on("error",function(error){
    console.log(error)
})
//do many things


//函数是一等公民. 函数也可以是变量、参数.
//(((add(2))(3))(4))() = 9;
add(2)(3)(4)() = 9
function add(number){
    //TODO
}

//log 日志
//console.errorog

desgin pattern




class Hero
class Equipment


Hero受伤的时候
发布一个 damage 事件
emit("damage")

subscribe("damage")

unsubscribe("damage")

异步
asynchronous




//--------------------------------------------------------
const Hero = {
    hp: 100
}



function checkDead(hero){
    if(hero.hp <= 0){
        //end the game
    }
}

function giveDefender(hero){
    if(hero.hp <= 50){
        //给护盾
    }
}

function friendBuff(hero){
    if(hero.hp <= 30){
        hero.hp += 10; 
    }
}


function damage(dmg,hero){
    hero.hp -= dmg;
    //add here
    event.emit("damage")        //发布这个事件

}



event;

event.subscribe("damage", fn ); //订阅




