// External Dependencies
import express, { Request, Response } from "express"
import { ObjectId } from "mongodb"
import { collections } from "../../setup/database"
import User from "../../models/user.model"


// Global Config
export const info_router = express.Router()
info_router.use(express.json())


// GET
info_router.get("/", async (_req: Request, res: Response) => {
    try {
        const users = (await collections.users?.find({}).toArray()) as unknown as User[]

        res.status(200).send(users)
    } catch (error) {
        res.status(500).send(error.message)
    }
})


info_router.get("/:id", async (req: Request, res: Response) => {
    const id = req?.params?.id

    try {

        const query = { _id: new ObjectId(id) }
        const user = (await collections.users?.findOne(query)) as unknown as User

        if (user) {
            res.status(200).send(user)
        } else {
            throw new Error
        }
    } catch (error) {
        res.status(404).send(`Unable to find matching document with id: ${req.params.id}`)
    }
})


// POST
info_router.post("/", async (req: Request, res: Response) => {
    try {
        const newUser = req.body as User;
        const result = await collections.users?.insertOne(newUser);

        result
            ? res.status(201).send(`Successfully created a new user with id ${result.insertedId}`)
            : res.status(500).send("Failed to create a new user.");
    } catch (error) {
        console.error(error);
        res.status(400).send(error.message);
    }
});

// PUT
info_router.put("/:id", async (req: Request, res: Response) => {
    const id = req?.params?.id;

    try {
        const updatedUser: User = req.body as User;
        const query = { _id: new ObjectId(id) };

        const result = await collections.users?.updateOne(query, { $set: updatedUser });

        result
            ? res.status(200).send(`Successfully updated user with id ${id}`)
            : res.status(304).send(`User with id: ${id} not updated`);
    } catch (error) {
        console.error(error.message);
        res.status(400).send(error.message);
    }
});

// DELETE
info_router.delete("/:id", async (req: Request, res: Response) => {
    const id = req?.params?.id;

    try {
        const query = { _id: new ObjectId(id) };
        const result = await collections.users?.deleteOne(query);

        if (result && result.deletedCount) {
            res.status(202).send(`Successfully removed user with id ${id}`);
        } else if (!result) {
            res.status(400).send(`Failed to remove user with id ${id}`);
        } else if (!result.deletedCount) {
            res.status(404).send(`User with id ${id} does not exist`);
        }
    } catch (error) {
        console.error(error.message);
        res.status(400).send(error.message);
    }
});