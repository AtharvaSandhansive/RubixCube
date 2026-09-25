//interface.ts

import arrow from "../assets/arrow.png";

export class Interface{

    private body: HTMLElement;
    private face: HTMLElement;

    constructor() {
        this.body = document.body;

        this.face = document.createElement("div");
        this.face.classList.add("cube-container");

        this.body.appendChild(this.face);

        this.createFace();
    }

    private createFaceElement(className: string): HTMLElement {

        const face = document.createElement("div");

        face.classList.add("cube-face", className);

        for (let i = 0; i < 9; i++) {

            const sticker = document.createElement("div");

            sticker.classList.add("sticker");

            face.appendChild(sticker);
        }

        return face;
    }

    private createFace(): void {

        const mainFace = this.createFaceElement("main-face");
        const upFace = this.createFaceElement("up-face");
        const downFace = this.createFaceElement("down-face");
        const leftFace = this.createFaceElement("left-face");
        const rightFace = this.createFaceElement("right-face");
        const backFace = this.createFaceElement("back-face");

        this.face.appendChild(mainFace);
        this.face.appendChild(upFace);
        this.face.appendChild(downFace);
        this.face.appendChild(leftFace);
        this.face.appendChild(rightFace);
        this.face.appendChild(backFace);
    }

    public updateGraphics(): void {

    }
}
