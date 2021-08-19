const { clear, log, table } = console
import { Socket } from 'socket.io'
import { Request, Response, NextFunction } from 'express'
import { init_server } from './_server_setup'

const { app, io } = init_server()

// Socket forbindelser
io.on('connection', (socket: Socket) => {
	const sid: string = socket.id
})

// Basic request
app.get('/', (req: Request, res: Response) => {
	res.render('index', req.meta)
})