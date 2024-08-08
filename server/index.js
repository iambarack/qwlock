const express = require('express')
const path = require('path');
const {pass} = require('./password.json')
var bodyParser = require('body-parser')

const app = express()
const port = 80
// parse application/x-www-form-urlencoded
app.use(bodyParser.urlencoded({ extended: true }))

// parse application/json
app.use(bodyParser.json())
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '/unlock.html'));
  console.log("req");
})

//primitive checks, can improved by 20-30x in terms of security
app.post('/unlock', (req, res) => {
    console.log(req.body);
    if (req.body.password) {
      const pw = req.body.password
      if (pw.length < 200 && pw.length > 6) {
        if (pw == pass) {
          console.log("match");
          res.send(JSON.stringify({val : "success"}))
        } else res.send(JSON.stringify({val : "failed3"}))
      } else res.send(JSON.stringify({val : "failed2"}))
    } else res.send(JSON.stringify({val : "failed"}))

})
app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})