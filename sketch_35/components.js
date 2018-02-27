// basic component

// Vue.component('child', {
//     props: ['text'],
//     template: `<div>{{ text }}</div>`
// })

//  prop types

Vue.component('child', {
    props: {
        count: {
            type: Number, 
            required: true
        },
        text: {
            type: String,
            required: true
        }
    },
    template: `<div> {{ count }} </div><div>{{ count }}</div>`
})

const app = new Vue({
    el: '#app',
    data(){
        return {
            message: 'sup bro.',
            count: 0
        }
    },
    methods: {
        increment() {
            this.count++;
        },
        decrement() {
            this.count--;
        }
    }
})