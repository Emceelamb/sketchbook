// Basic Hello World

const sup = new Vue({
    el: '#sup',
    data: {
        sup: 'Sup bro.'
    }
});

// List Items

const list = [
    'this',
    'that',
    'something else'
];

function listItems(){
    let full_list = '';
    for(let i = 0; i<list.length; i++){
        full_list = full_list + `<li> ${list[i]}</li>`
    };

    const contain = document.querySelector('#list');
    contain.innerHTML = `<ul> ${full_list}</ul>`
}

listItems();

// v-for loop

const listApp = new Vue({
    el:'#listApp',
    data:{
        title: 'v for list: ',
        list: [
            'this',
            'that',
            'something else'
        ]
    }
});

// Model
const model = new Vue({
    el: '#model',
    data(){
        return {
            msg: 'type something here'
        }
    }
});