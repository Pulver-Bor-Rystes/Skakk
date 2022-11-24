import { Database } from './api/database';
import { Users } from './api/users';
import { Server } from './server';
import { Games, Invite } from "./api/games"

Server.on('ping', (req, data) => {
  console.log('\nreceived topic: ping');
  console.log(data);
  req.ok_sid('pong');
});

Database.init();
Server.init();

console.clear()
console.log("Det kører sgu")

let key = Invite.key("rasmus", "emil")

// Invite.new("rasmus", "VrQMTGnxFKbaigfJidXohm1oFE4ie3VtLz7agoC7dG5OrFNyAtzOciJawlWGlJnJ")
//   .then(res => console.log("1r:", res))
//   .catch(err => console.log("1e:", err))

// Invite.new("emil", "rasmus")
//   .then(res => console.log("2r:", res))
//   .catch(err => console.log("2e:", err))



// Games.state(key)
//   .then(fen => console.log("3r:", fen))
//   .catch(err => console.log("3e:", err))


// Games.move(key, "e4")
//   .then(fen => console.log("4r:", fen))
//   .catch(err => console.log("4e:", err))
// Games.move(key, "d5")
//   .then(fen => console.log("4.r:", fen))
//   .catch(err => console.log("4.e:", err))
  

// Games.state(key)
//   .then(fen => console.log("5r:", fen))
//   .catch(err => console.log("5e:", err))



// Users.signup("rasmus", "kodeord")
//   .then(val => {
//     console.log("yeah:", val)
//   })
//   .catch(err => {
//     console.log("err:", err)
//   })
