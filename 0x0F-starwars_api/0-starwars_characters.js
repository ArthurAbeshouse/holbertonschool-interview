#!/usr/bin/node

const request = require('request')

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`, async function (error, response, body) {
  if (error) {
    console.log(error)
  }
  for (const i of JSON.parse(body).characters) {
    await new Promise((resolve, reject) => {
      request(i, (error, response, body) => {
        if (error) {
          console.log(error)
        }
        console.log(JSON.parse(body).name)
        resolve()
      })
    })
  }
})
